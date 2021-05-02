#include "DAG.h"

vector <quat_item> QUATS;   //��Ԫʽ
vector <quat_item> NEW_QUATS;   //�ݴ��Ż������Ԫʽ
vector <dagNode> DAG;  //dagͼ
map <string,int> mapDag; //���ڲ��ұ��
vector<string> ftemp;   //����������ʱ����
int index=0;  //��һ�ڵ���
int N=3;    //ѭ���Ż�����

bool isBinaryOp(string op){ //�ж��Ƿ��Ƕ�Ԫ�����
    bool flag=false;
    if(op=="+" || op=="-" || op=="*" || op=="/" || op=="&&" || op=="||" ||
       op=="<" || op==">" || op=="==" || op=="<=" || op==">=" || op=="!="||op=="[]")
        flag = true;
    return flag;
}

int isBothConstant(string op1,string op2){ //�ж��������Ƿ��ǳ���,ֻ�ж�i��r�ͳ���
    bool flag=false;
    string s1="";
    string s2="";
    if(op1.length()>=8) {
        for(int i=0;i<8;i++){
            s1 += op1[i];
            s2 += op2[i];
        }
        if((s1=="#const_i" || s1== "#const_r")&& (s2=="#const_i" || s2=="#const_r")) flag=true;
    }
    return flag;
}

void addAssignDag(quat_item q,int Num=-1) { //��Ӹ�ֵ��Ԫʽ(=,b,_,a)

    if(Num==-1){
        if(mapDag.count(q.op1)==0){ //b������ʱ��ӽ��
            dagNode dag_n;
            dag_n.num = index;
            dag_n.mark.push_back(q.op1);
            DAG.push_back(dag_n);
            mapDag[q.op1]=index;
            Num = index;
            index++;
        }
        else{
            Num = mapDag[q.op1];    //b�Ѵ���ʱ��ȡ����
        }
    }

    if(mapDag.count(q.t)>0){     //a������ɾ��������� �����ͬ��ַ������ɾ)
        int Num2;
        Num2 = mapDag[q.t];
        if(q.t.length()>=3 && q.t[0]=='#' && q.t[1]=='p' && q.t[2]=='_' && DAG[Num2].opt=="[]") {}
        else if(DAG[Num2].mark[0]!=q.t){
            for(vector<string>::iterator iter=DAG[Num2].mark.begin();iter!=DAG[Num2].mark.end();iter++){
                if(*iter==q.t) {
                    DAG[Num2].mark.erase(iter);
                    break;
                }
            }
        }
    }
    string s="";
    for(int i=0;i<6;i++) s += q.t[i];
    if(s=="#temp_") DAG[Num].mark.push_back(q.t);   //��ʱ����ֱ�Ӹ��ϼ���
    else {  //����ʱ�����Ƿ��ƶ��������
        if(DAG[Num].mark.size()==0) DAG[Num].mark.push_back(q.t);
        else{
            string ss="";
            for(int i=0;i<6;i++) ss += DAG[Num].mark[0][i];
            if(ss=="#temp_"){
                DAG[Num].mark.insert(DAG[Num].mark.begin(),q.t); //��Ϊ�����
            }
            else DAG[Num].mark.push_back(q.t);
        }
    }
    mapDag[q.t]=Num;    //����map��ͬʱ��֮ǰ��ɾ��
}

string calculateConst(quat_item q){     //���������������,ֻ����i/r�ͳ���
    string opp1="";
    string opp2="";
    for(unsigned int i=9;i<q.op1.length();i++) opp1+=q.op1[i];
    for(unsigned int i=9;i<q.op2.length();i++) opp2+=q.op2[i];
    double op1, op2;
    double result;
    std::stringstream ss, ss1;
    ss << opp1;
    ss >> op1;
    ss1 << opp2;
    ss1 >> op2;
    if(q.w=="+") result= op1+op2;
    else if(q.w=="-") result= op1-op2;
    else if(q.w=="*") result= op1*op2;
    else if(q.w=="/") result= op1/op2;
    else if(q.w==">") result= op1>op2;
    else if(q.w=="<") result= op1<op2;
    else if(q.w=="==") result= op1==op2;
    else if(q.w==">=") result= op1>=op2;
    else if(q.w=="<=") result= op1<=op2;
    else if(q.w=="!=") result= op1!=op2;
    else if(q.w=="&&") result= op1&&op2;
    else result= op1||op2;
    ostringstream oss;
    string str;
    oss << result;
    if(q.op1[7]=='i' && q.op2[7]=='i') str="#const_i_"+oss.str();
    else str="#const_r_"+oss.str();
    return str;
}

int findWab(quat_item q){ //����ֵΪaWb�Ľڵ��ţ�û���򴴽�
    for(unsigned int i=0;i<DAG.size();i++){ //awb����ʱ
        if(DAG[i].opt==q.w){
            bool flag1=false; //�����Ƿ���a���
            if(DAG[i].leftChild>-1 && DAG[i].rightChild>-1) { //���к���ʱ
                for(unsigned int j=0;j<DAG[DAG[i].leftChild].mark.size();j++){
                    if(DAG[DAG[i].leftChild].mark[j]==q.op1){
                        flag1=true;
                        break;
                    }
                }
                if(flag1==true){ //����������Ϊaʱ�����Һ���
                    for(unsigned int j=0;j<DAG[DAG[i].rightChild].mark.size();j++){
                        if(DAG[DAG[i].rightChild].mark[j]==q.op2) return int(i);
                    }
                }
            }
        }
    }
    int Num;
    int Num1,Num2;
    if(mapDag.count(q.op1)>0) Num1=mapDag[q.op1];
    else {  //����������1���
        dagNode dag_n1;
        dag_n1.num = index;
        dag_n1.mark.push_back(q.op1);
        DAG.push_back(dag_n1);
        mapDag[q.op1]=index;
        Num1=index;
        index++;
    }
    if(mapDag.count(q.op2)>0) Num2=mapDag[q.op2];
    else{ //����������2���
        dagNode dag_n2;
        dag_n2.num = index;
        dag_n2.mark.push_back(q.op2);
        DAG.push_back(dag_n2);
        mapDag[q.op2]=index;
        Num2 = index;
        index++;
    }
    dagNode dag_result;  //�����û��mark���ȴ����ø�ֵ��Ԫʽ���
    dag_result.num=index;
    dag_result.opt=q.w;
    dag_result.leftChild=Num1;
    dag_result.rightChild=Num2;
    DAG.push_back(dag_result);
    //mapDag[oss.str()]=index;
    Num=index;
    index++;
    return Num;
}

int findWa(quat_item q){  //����ֵΪwa�Ľڵ��ţ�û�������
    for(unsigned int i=0;i<DAG.size();i++){
        if(DAG[i].opt==q.w){
            if(DAG[i].leftChild>-1){
                for(unsigned int j=0;i<DAG[DAG[i].leftChild].mark.size();j++){
                    if(DAG[DAG[i].leftChild].mark[j]==q.op1) return int(i);
                }
            }
        }
    }
    int Num0;
    int Num;
    if(mapDag.count(q.op1)==0){ //û���򴴽�a���
        dagNode dag_a;
        dag_a.num = index;
        dag_a.mark.push_back(q.op1);
        DAG.push_back(dag_a);
        mapDag[q.op1]=index;
        Num=index;
        index++;
    }
    else Num=mapDag[q.op1];

    dagNode dag_result;  //�����û��mark���ȴ����ø�ֵ��Ԫʽ���
    dag_result.num=index;
    dag_result.opt=q.w;
    dag_result.leftChild=Num;
    DAG.push_back(dag_result);
    //mapDag[ss]=index;
    Num0=index;
    index++;
    return Num0;
}

void addDagNode(quat_item q){
    if(q.w=="="){   //��ֵ��Ԫʽ(=,b,_,a)
        addAssignDag(q);
    }
    else if(isBinaryOp(q.w)){   //�����Ԫ������Ԫʽ
        if(isBothConstant(q.op1,q.op2)) {  //�������ֳ�������������
            quat_item q1;
            q1.w = "=";
            q1.t = q.t;
            q1.op1= calculateConst(q);  ////������
            addAssignDag(q1);   //����ֵ��Ԫʽ��Ӽ���
        }
        else{   //������Ԫʽ(w,a,b,c)
            int Num;
            Num=findWab(q);
            addAssignDag(q,Num);
        }
    }
    else if(q.w=="!" || q.w=="if" || q.w=="do" || q.w=="ret"){  //����һԪʽ
        if(q.w=="!") {
            bool isConst=false;
            if(q.op1.length()>=8){
                string qs="";
                for(unsigned int i=0;i<8;i++) qs+=q.op1[i];
                if(qs=="#const_i" || qs=="#const_r" || qs=="#const_c") isConst=true;
            }
            if(isConst) {   //����������
                std::stringstream ss;
                ss<<q.op1;
                if(q.op1[7]=='i'||q.op1[7]=='r'){ //�����򸡵�������
                    double op;
                    ss>>op;
                    quat_item q2;
                    q2.w = "=";
                    if(!op) q2.op1="1";
                    else q2.op1="0";
                    q2.t = q.t;
                    addAssignDag(q2);
                }
                else {  //�ַ�����
                    char op;
                    ss>>op;
                    quat_item q2;
                    q2.w = "=";
                    if(!op) q2.op1="1";
                    else q2.op1="0";
                    q2.t = q.t;
                    addAssignDag(q2);
                }
            }
            else{ //������Ԫʽ(!,a,_,t)
                int Num;
                Num=findWa(q);
                addAssignDag(q,Num);
            }
        }
        else if(q.w=="if" || q.w=="do"){ //����(if,a,_,ƫ����)  (do,a,_,ƫ����)
            q.w=q.w+"_"+q.t;   //�޸ĳ�if_ƫ������do_ƫ��������ʽ
            findWa(q);  //��ӽڵ㼴��
        }
        else{   //����(ret,_,_,����ֵ)
            q.op1=q.t;
            findWa(q);
        }
    }
    else{      //��������������Ԫʽ
        dagNode dagN;
        dagN.num = index;
        dagN.opt = q.w;
        dagN.mark.push_back(q.op1);
        dagN.mark.push_back(q.op2);
        dagN.mark.push_back(q.t);
        DAG.push_back(dagN);
        index++;
    }
}
bool isNormalOpt(string opt){
    bool flag=false;
    if(opt=="=" || isBinaryOp(opt) || opt=="!" ) flag=true;
    else if(opt.length()>=3 ){
        string ss="";
        for(int i=0;i<3;i++) ss+=opt[i];
        if(ss=="if_" || ss=="do_" || ss=="ret") flag=true;
    }
    return flag;
}
void creatNEW_QUATS(){      //����DAGͼ������Ԫʽ
    for(unsigned int i=0;i<DAG.size();i++){ //����DAGͼ
        int isArrayFlag=0;
        if(DAG[i].leftChild!=-1 || DAG[i].rightChild!=-1){ //��ΪҶ�ӽڵ�ʱ  //ret����DAG������Ԫʽʱ��Ҫ�ѷ���ֵ�����
            quat_item q;
            q.op1="_";
            q.op2="_";
            if(DAG[i].leftChild!=-1) q.op1=DAG[DAG[i].leftChild].mark[0];
            if(DAG[i].rightChild!=-1) q.op2=DAG[DAG[i].rightChild].mark[0];
            if(DAG[i].opt.length()>2){
                string s="";
                for(int p=0;p<3;p++) s+=DAG[i].opt[p];
                if(s=="if_"){
                    q.w = "if";
                    string st="";
                    for(unsigned int t=3;t<DAG[i].opt.length();t++) st+=DAG[i].opt[t];
                    q.t = st;
                }
                else if(s=="do_"){
                    q.w = "do";
                    string st="";
                    for(unsigned int t=3;t<DAG[i].opt.length();t++) st+=DAG[i].opt[t];
                    q.t = st;
                }
                else if(s=="ret"){
                    q.w = "ret";
                    q.t = q.op1;
                    q.op1 = "_";
                }
                else {
                    q.w = DAG[i].opt;
                    q.t = DAG[i].mark[0];
                }
            }
            else {
                if(DAG[i].opt=="[]") isArrayFlag=1;
                q.w=DAG[i].opt;q.t=DAG[i].mark[0];
                }
                NEW_QUATS.push_back(q);
                if(isArrayFlag){
                    for(unsigned int t=1;t<DAG[i].mark.size();t++){  //����ǵ����鶨�崦��
                        q.t=DAG[i].mark[t];
                        NEW_QUATS.push_back(q);
                    }
                }
        }
        if(isArrayFlag) continue;
        if(DAG[i].opt!="" && !isNormalOpt(DAG[i].opt)){
            //������Ԫʽ
            quat_item q;
            q.w = DAG[i].opt;
            q.op1 = DAG[i].mark[0];
            q.op2 = DAG[i].mark[1];
            q.t = DAG[i].mark[2];
            NEW_QUATS.push_back(q);

        }
        else{
            for(unsigned int j=1;j<DAG[i].mark.size();j++){  //��Ӹ�ֵ��Ԫʽ
                if(DAG[i].mark[j].length()>=5){
                    string ss="";
                    for(int k=0;k<5;k++) ss+=DAG[i].mark[j][k];
                    if(ss!="#temp") { //Ϊ����ʱ����ʱ
                        quat_item q;
                        q.w="=";
                        q.op1=DAG[i].mark[0];
                        q.op2="_";
                        q.t=DAG[i].mark[j];
                        NEW_QUATS.push_back(q);
                    }
                    else if(find(ftemp.begin(),ftemp.end(),DAG[i].mark[j])!=ftemp.end()){  //�������ص���ʱ����
                       quat_item q;
                        q.w="=";
                        q.op1=DAG[i].mark[j];
                        q.op2="_";
                        q.t=DAG[i].mark[0];
                        NEW_QUATS.push_back(q);
                    }
                }
                else{
                    quat_item q;
                    q.w="=";
                    q.op1=DAG[i].mark[0];
                    q.op2="_";
                    q.t=DAG[i].mark[j];
                    NEW_QUATS.push_back(q);
                }
            }
        }
    }
    //������Ԫʽ˳��ĵ���
    for(unsigned int i=0;i<NEW_QUATS.size();i++){
        if(NEW_QUATS[i].t.length()>=3 && NEW_QUATS[i].t[0]=='#' &&NEW_QUATS[i].t[1]=='p' && NEW_QUATS[i].t[2]=='_'){
            for(unsigned int j=i+1;j<NEW_QUATS.size();j++){
                if(NEW_QUATS[j].w=="[]" && NEW_QUATS[j].t==NEW_QUATS[i].t){
                    //����˳��
                    quat_item q;
                    q = NEW_QUATS[i];
                    NEW_QUATS[i] = NEW_QUATS[j];
                    NEW_QUATS[j] = q;
                    break;
                }
            }
        }
    }


}

void showDAG(){
    for(unsigned int i=0;i<DAG.size();i++){

        cout<<"-------------"<<endl;
        cout<<"��ţ�"<<DAG[i].num<<endl;
        if(DAG[i].opt=="") cout<<"�������"<<"��"<<endl;
        else cout<<"�������"<<DAG[i].opt<<endl;
        cout<<"���� �Һ���:"<<DAG[i].leftChild<< " "<<DAG[i].rightChild<<endl;
        if(DAG[i].mark.size()==0) cout<<"�ޱ��"<<endl;
        else cout<<"����ǣ�"<<DAG[i].mark[0]<<endl;
        for(unsigned j=1;j<DAG[i].mark.size();j++) cout<<"����ǣ�"<<DAG[i].mark[j]<<endl;

    }
}
void showQUATS(){
    for(unsigned int i=0;i<QUATS.size();i++){
        cout<<std::left<<setw(3)<<i<<"("<<QUATS[i].w<<","<<QUATS[i].op1<<","<<QUATS[i].op2<<","<<QUATS[i].t<<")"<<endl;
    }
}

void showNEW_QUATS(){
    cout<<"\n�Ż������Ԫʽ:"<<endl;
    for(unsigned int i=0;i<NEW_QUATS.size();i++){
        cout<<"("<<NEW_QUATS[i].w<<","<<NEW_QUATS[i].op1<<","<<NEW_QUATS[i].op2<<","<<NEW_QUATS[i].t<<")"<<endl;
    }
}

void optimizeOnce(){       //�Ż�һ��
        //��ʼ��
        DAG.clear();
        mapDag.clear();
        NEW_QUATS.clear();
        index=0;
        //����ת����ƫ��������ɶ�Ӧ��Ԫʽ���
        for(int i=0;i<int(QUATS.size());i++){
            if(QUATS[i].w=="jmpc" || QUATS[i].w=="jmpb" || QUATS[i].w=="if" || QUATS[i].w=="el" || QUATS[i].w=="do" || QUATS[i].w=="we"){
                int dis;
                std::stringstream ss;
                ss<<QUATS[i].t;
                ss>>dis;
                dis = dis+i;    //ʵ��λ��
                ostringstream oss;
                oss <<dis;
                QUATS[i].t = oss.str();
            }
        }
        vector<unsigned int> Jumpc;  //��jmpc��ת������Ԫʽλ��
        vector<unsigned int> Jumpb;  //��jmpb��ת������Ԫʽλ��
        vector<unsigned int> Ifs;  //��if��ת������Ԫʽλ��
        vector<unsigned int> Els;  //��el��ת������Ԫʽλ��
        vector<unsigned int> Dos;  //��do��ת������Ԫʽλ��
        vector<unsigned int> Wes;  //��we��ת������Ԫʽλ��
        map<string,string> JumpcI;    //��ÿ����ת��Ԫʽ�Ż���Ӧ����ת����λ��
        map<string,string> JumpbI;
        map<string,string> IfI;
        map<string,string> ElI;
        map<string,string> DoI;
        map<string,string> WeI;
        for(unsigned int i=0;i<QUATS.size();i++){
            if(QUATS[i].w=="jmpc"){
                std::stringstream ss;
                ss<<QUATS[i].t;
                unsigned int t;
                ss>>t;
                Jumpc.push_back(t);
            }
            else if(QUATS[i].w=="jmpb"){
                std::stringstream ss;
                ss<<QUATS[i].t;
                unsigned int t;
                ss>>t;
                Jumpb.push_back(t);
            }
            else if(QUATS[i].w=="if"){
                std::stringstream ss;
                ss<<QUATS[i].t;
                unsigned int t;
                ss>>t;
                Ifs.push_back(t);
            }
            else if(QUATS[i].w=="el"){
                std::stringstream ss;
                ss<<QUATS[i].t;
                unsigned int t;
                ss>>t;
                Els.push_back(t);
            }
            else if(QUATS[i].w=="do"){
                std::stringstream ss;
                ss<<QUATS[i].t;
                unsigned int t;
                ss>>t;
                Dos.push_back(t);
            }
            else if(QUATS[i].w=="we"){
                std::stringstream ss;
                ss<<QUATS[i].t;
                unsigned int t;
                ss>>t;
                Wes.push_back(t);
            }
        }

        int *a;
        int n=QUATS.size();
        a = (int *)malloc(sizeof(int) * n);
        for (int i = 1; i < n; i++)  a[i] = 0;  //�����Ԫʽ��ǣ�1��ʾ�����
        for(unsigned int i=0;i<QUATS.size();i++){
            if(QUATS[i].w=="call" || QUATS[i].w=="ret" || QUATS[i].w=="pvall" || QUATS[i].w=="pvret" || QUATS[i].w=="f_begin " || QUATS[i].w=="f_end"){
                //��һ��Ϊ���
                if(i+1<QUATS.size()) a[i+1]=1;
            }
            else if(QUATS[i].w=="if" || QUATS[i].w=="el" || QUATS[i].w=="do" || QUATS[i].w=="we" || QUATS[i].w=="jmpc" ||QUATS[i].w=="jmpb"){
                //��һ��Ϊ���
                if(i+1<QUATS.size()) a[i+1]=1;
                //ת�Ƶ���Ϊ���
                std::stringstream ss;
                ss<<QUATS[i].t;
                int t;
                ss>>t;
                a[t]=1;
            }
        }
        //�ֿ�����Ż�
        for(int unsigned i=0;i<QUATS.size();i++){
            if(QUATS[i].w=="call") {ftemp.push_back(QUATS[i].t);}
            if(a[i]==1){
                creatNEW_QUATS();
                DAG.clear();
                mapDag.clear();
                index=0;
                if(find(Jumpc.begin(),Jumpc.end(),i)!=Jumpc.end()){
                    ostringstream oss,os;
                    oss <<i;
                    os<<NEW_QUATS.size();
                    JumpcI[oss.str()]= os.str();
                }
                if(find(Jumpb.begin(),Jumpb.end(),i)!=Jumpb.end()){
                    ostringstream oss,os;
                    oss <<i;
                    os<<NEW_QUATS.size();
                    JumpbI[oss.str()]= os.str();
                }
                if(find(Ifs.begin(),Ifs.end(),i)!=Ifs.end()){
                    ostringstream oss,os;
                    oss <<i;
                    os<<NEW_QUATS.size();
                    IfI[oss.str()]= os.str();
                }
                if(find(Els.begin(),Els.end(),i)!=Els.end()){
                    ostringstream oss,os;
                    oss <<i;
                    os<<NEW_QUATS.size();
                    ElI[oss.str()]= os.str();
                }
                if(find(Dos.begin(),Dos.end(),i)!=Dos.end()){
                    ostringstream oss,os;
                    oss <<i;
                    os<<NEW_QUATS.size();
                    DoI[oss.str()]= os.str();
                }
                if(find(Wes.begin(),Wes.end(),i)!=Wes.end()){
                    ostringstream oss,os;
                    oss <<i;
                    os<<NEW_QUATS.size();
                    WeI[oss.str()]= os.str();
                }
            }
            addDagNode(QUATS[i]);
        }
        creatNEW_QUATS();
        for(unsigned int i=0;i<NEW_QUATS.size();i++){
            if(NEW_QUATS[i].w=="jmpc") NEW_QUATS[i].t = JumpcI[NEW_QUATS[i].t];   //�޸�jmpc��Ԫʽ��ƫ����
            else if(NEW_QUATS[i].w=="jmpb") NEW_QUATS[i].t = JumpbI[NEW_QUATS[i].t]; //�޸�jmpb��Ԫʽ��ƫ����
            else if(NEW_QUATS[i].w=="if") NEW_QUATS[i].t = IfI[NEW_QUATS[i].t];  //�޸�if��Ԫʽ��ƫ����
            else if(NEW_QUATS[i].w=="el") NEW_QUATS[i].t = ElI[NEW_QUATS[i].t];  //�޸�el��Ԫʽ��ƫ����
            else if(NEW_QUATS[i].w=="do") NEW_QUATS[i].t = DoI[NEW_QUATS[i].t];  //�޸�do��Ԫʽ��ƫ����
            else if(NEW_QUATS[i].w=="we") NEW_QUATS[i].t = WeI[NEW_QUATS[i].t];  //�޸�we��Ԫʽ��ƫ����
        }
        for(int i=0;i<int(NEW_QUATS.size());i++){  //ʵ��λ�ñ�Ϊƫ����
            if(NEW_QUATS[i].w=="jmpc" || NEW_QUATS[i].w=="jmpb" || NEW_QUATS[i].w=="if" || NEW_QUATS[i].w=="el" || NEW_QUATS[i].w=="do" || NEW_QUATS[i].w=="we"){
                int dis;
                std::stringstream ss;
                ss<<NEW_QUATS[i].t;
                ss>>dis;
                dis = dis-i;    //ʵ��λ��
                ostringstream oss;
                oss <<dis;
                NEW_QUATS[i].t = oss.str();

            }
        }

        QUATS=NEW_QUATS;
}

void optimizeQuats(){
    int num=N;
    while(num--){
       optimizeOnce();
    }
}
