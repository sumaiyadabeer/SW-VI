#include <cstdio>
#include<stdio.h>
#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <set>
#define MAX_NFA_STATES 10
#define MAX_ALPHABET_SIZE 10
using namespace std;
// Representation of an NFA state
class NFAstate
{
    public:
        int transitions[10][10];
        NFAstate()
        {
            for (int i = 0; i < 10; i++)
                for (int j = 0; j<10; j++)
                    transitions[i][j] = -1;
        }
}*NFAstates;
// Representation of a DFA state
struct DFAstate
{
        bool finalState;
        bitset<10> constNFAstates;
        bitset<10> transitions[10];
        int symTransitions[10];
};
set<int>::iterator it;
set<int> NFA_finalStates;
vector<int> DFA_finalStates;
vector<DFAstate*> DFAstates;
queue<int> incompleteDFAstates;
int N, M; // N -> No. of stattes, M -> Size of input alphabet
// finds the epsilon closure of the NFA state "state" and stores it into "closure"
void epsilonClosure(int state, bitset<10> &closure)
{
    for (int i = 0; i < N && NFAstates[state].transitions[0][i] != -1; i++)
        if (closure[NFAstates[state].transitions[0][i]] == 0)
        {
            closure[NFAstates[state].transitions[0][i]] = 1;
            epsilonClosure(NFAstates[state].transitions[0][i], closure);
        }
}
// finds the epsilon closure of a set of NFA states "state" and stores it into "closure"
void epsilonClosure(bitset<10> state,
        bitset<10> &closure)
{
    for (int i = 0; i < N; i++)
        if (state[i] == 1)
            epsilonClosure(i, closure);
}
// returns a bitset representing the set of states the NFA could be in after moving
// from state X on input symbol A
void NFAmove(int X, int A, bitset<10> &Y)
{
    for (int i = 0; i < N && NFAstates[X].transitions[A][i] != -1; i++)
        Y[NFAstates[X].transitions[A][i]] = 1;
}
// returns a bitset representing the set of states the NFA could be in after moving
// from the set of states X on input symbol A
void NFAmove(bitset<10> X, int A, bitset<10> &Y)
{
    for (int i = 0; i < N; i++)
        if (X[i] == 1)
            NFAmove(i, A, Y);
}
int retrn(char c)
{
		if(c=='0')
	return 0;
	if(c=='1')
	return 1;
		if(c=='2')
	return 2;
		if(c=='3')
	return 3;
		if(c=='4')
	return 4;
		if(c=='5')
	return 5;
		if(c=='6')
	return 6;
		if(c=='7')
	return 7;
		if(c=='8')
	return 8;
		if(c=='9')
	return 9;
	
	
	
	
}


int main()
{
    int i, j, X, Y, A, T, F, D;
       FILE *fp,*fpo;
       char string[30];
        char arstring[30][30];
       
		fp=fopen("input.txt","r");
		
		for(i=0;i<30;i++){
		for(j=0;j<30;j++){
		arstring[30][30]='\0';	
		}	
		}
		i=0;
		
		while(!feof(fp)){
				fgets(string,30,fp);
				for(j=0;j<strlen(string)-1;j++){
				if(string[j]=='\n')
				break;
			//	cout<<	string[j]<<endl;
				arstring[i][j]=string[j];	
				}
                //cout<<arstring[i]<<endl;
		i++;	
	
		}
		
			rewind(fp);
			int cn=0,flag=0;
		while(!feof(fp)){
				fgets(string,30,fp);
				cn=0;
				for(i=0;i<30;i++)
				{
					if(!strncmp(arstring[i],string,9)){
						cn++;
				//	cout<<"match cn"<<cn<<"   "<<arstring[i]<<"    "<<string<<endl;	
					}
				
				}
				if(cn>=2){
					cout<<"it is nfa"<<endl;
					flag=1;
				}
				
		}
		if(flag==0)
		{
			cout<<"nt nfa"<<endl;
			return 1;
		}
		
		rewind(fp);
		//calculate no of lines done
		int count=1;
		N=1;
		M=1;
		F=1;
		T=0;
		int c;
	fgets(string,30,fp);
	int k=0;
			while(!feof(fp)){
					
				fgets(string,30,fp);
				if(count==1){			//input states
					for(int i=0;i<strlen(string);i++){
						if(string[i]==',')
						N++;
					}
				//	cout<<" count 1"<<strlen(string)<<string<<endl;
					 NFAstates = new NFAstate[N];
				}
				else if(count==2){			//input alphabet
				    for(int i=0;i<strlen(string);i++){
						if(string[i]==',')
							M++;
						
							
					
					}
							//	cout<<" count 2"<<strlen(string)<<string<<endl;	
					
				}
				else if(count==3) {       //final state
			    for(int i=0;i<strlen(string);i++){
						if(string[i]==',')
						F++;
					}
							//	cout<<" count 3"<<strlen(string)<<string<<endl;
				
					 for(int i=2;i<strlen(string)-2;i++){
					 i=i+2;
					 NFA_finalStates.insert(retrn(string[i]));	
				//	  cout<<"final sate"<<string[i]<<endl;	
					 }
											//in loop
				}else if(string[0]=='d'){   	//transition lines
				 T++;
		
		
		
		
				X=retrn(string[3]);
				A=retrn(string[5]);
				j=retrn(string[9]);
		for(k=0; NFAstates[X].transitions[A][k]!=-1;k++)
		{
		//	cout<<"other transition "<<endl;
		}
				
				 NFAstates[X].transitions[A][k] = j; 
		cout<<"insert "<<X<<" "<<A<<" "<<k<<" "<<j<<endl;
				}
			    else{			
				break;		
			    			//	cout<<" count... "<<strlen(string)<<string<<endl;
			    }
			    
		count++;
		if(feof(fp))
		cout<<"end file"<<endl;
	
			}
			fclose(fp);
		cout<<"    N"<<N<<"   M"<<M<<"  F"<<F<<"   T"<<T<<endl;
		T=-1;
		  for (it= NFA_finalStates.begin(); it!= NFA_finalStates.end(); ++it)
    std::cout << ' ' << *it;
		//	cout<<NFAstates[1].transitions[1][1] <<endl; 
   /* // read in the underlying NFA
    ifstream fin("NFA.txt");
    fin >> N >> M;
  //  cout<<N<<"   "<<M;
    NFAstates = new NFAstate[N];
    fin >> F;
   
    for (i = 0; i < F; i++)
    {
        fin >> X;
        NFA_finalStates.insert(X);
    }
    fin >> T;
     cout<<T;
    while (T--)
    {
        fin >> X >> A >> Y;					//y no of transition
    
        for (i = 0; i < Y; i++)
        {
            fin >> j;
            NFAstates[X].transitions[A][i] = j;       //chk for -1 in each row... of alphabet trans ;( put where -1 
        }
    }
    fin.close(); */
    // construct the corresponding DFA
    D = 1;
    DFAstates.push_back(new DFAstate);
    DFAstates[0]->constNFAstates[0] = 1;
    epsilonClosure(0, DFAstates[0]->constNFAstates);
    for (j = 0; j < N; j++)
        if (DFAstates[0]->constNFAstates[j] == 1 && NFA_finalStates.find(j) != NFA_finalStates.end())
        {
            DFAstates[0]->finalState = true;
            DFA_finalStates.push_back(0);
        // cout<<"if is executed"<<endl;
            break;
        }
        else{
       	//cout<<"else is "<<endl;
        }
    incompleteDFAstates.push(0);
 
    while (!incompleteDFAstates.empty())
    {
        X = incompleteDFAstates.front();
        incompleteDFAstates.pop();
        for (i = 1; i <= M; i++)
        {
        //	cout<<"i is less than M"<<endl;
            NFAmove(DFAstates[X]->constNFAstates, i, DFAstates[X]->transitions[i]);
            epsilonClosure(DFAstates[X]->transitions[i],DFAstates[X]->transitions[i]);
            for (j = 0; j < D; j++)
                if (DFAstates[X]->transitions[i]
                        == DFAstates[j]->constNFAstates)
                {
                    DFAstates[X]->symTransitions[i] = j;
                    break;
                }
            if (j == D)
            {
            	//cout<<"loop j=D"<<endl;
                DFAstates[X]->symTransitions[i] = D;
                DFAstates.push_back(new DFAstate);
                DFAstates[D]->constNFAstates
                        = DFAstates[X]->transitions[i];
                for (j = 0; j < N; j++){
                	if(NFA_finalStates.find(j) != NFA_finalStates.end())
                //	cout<<"cond 2 satisfied"<<endl;
                	
                    if (DFAstates[D]->constNFAstates[j] == 1
                            && NFA_finalStates.find(j) != NFA_finalStates.end())
                    {
                        DFAstates[D]->finalState = true;
                        DFA_finalStates.push_back(D);
                     // cout<<"j is less than N "<<endl;
                        break;
                    }
                }
                incompleteDFAstates.push(D);
               // cout<<"push D "<<D<<endl;
                D++;
            }
        }
    }
    // write out the corresponding DFA
    
    
    
    fpo=fopen("output.txt","w");
if(fpo==NULL)
printf("file not open");

fprintf(fpo,"<QD,ED,dD,Q0,FD>\n");
fprintf(fpo,"QD:{");
for(i=0;i<D;i++){
if(i<D-1)	
fprintf(fpo,"Q%d,",i);
if(i==D-1)
fprintf(fpo,"Q%d}\n",i);
}
fprintf(fpo,"ED:{");
for(i=0;i<M;i++){
	if(i<M-1)	
fprintf(fpo,"%d,",i);
if(i==M-1)
fprintf(fpo,"%d}\n",i);
}
// fprintf(fpo," %d\n",DFA_finalStates.size()); //this line is only fr checking..remove it finally
  fprintf(fpo,"FD:{ ");
 k=0;
 for (vector<int>::iterator it = DFA_finalStates.begin(); it
            != DFA_finalStates.end(); it++){
            k=*it;
           
          if(it != DFA_finalStates.end())
            fprintf(fpo,"%d,",k);
            else
            fprintf(fpo,"%d",k);
            cout<<"loop executed";	
            }
            fprintf(fpo,"}\n");
       // fout << " " << *it;
   // fout << "\n";
  

   for (i = 0; i < D; i++)
    {
        for (j = 1; j <= M; j++)
        fprintf(fpo,"dD(QD%d,%d):%d   \n"  ,i,j,DFAstates[i]->symTransitions[j]);
           
    }
    
fclose(fpo);
//fputs(fname,fptname);
//fprintf(fptrno,"%d\n",rno);
 /*  ofstream fout("kfa.txt");
    fout << D << " " << M << "\n" << DFA_finalStates.size();
    for (vector<int>::iterator it = DFA_finalStates.begin(); it
            != DFA_finalStates.end(); it++)
        fout << " " << *it;
    fout << "\n";
    for (i = 0; i < D; i++)
    {
        for (j = 1; j <= M; j++)
            fout << i << " " << j << " "
                    << DFAstates[i]->symTransitions[j] << "\n";
    }
    fout.close();*/
    return 0;
}
