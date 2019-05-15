#include <cstdio>
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
int main()
{
    int i, j, X, Y, A, T, F, D;
    // read in the underlying NFA
    ifstream fin("NFA.txt");
    fin >> N >> M;
    NFAstates = new NFAstate[N];
    fin >> F;
    for (i = 0; i < F; i++)
    {
        fin >> X;
        NFA_finalStates.insert(X);
    }
    fin >> T;
    while (T--)
    {
        fin >> X >> A >> Y;
        for (i = 0; i < Y; i++)
        {
            fin >> j;
            NFAstates[X].transitions[A][i] = j;
            	cout<<"insert "<<X<<" "<<A<<" "<<i<<" "<<j<<endl;
        }
    }
    fin.close();
    cout<<" T"<<T<<"  F"<<F<<" N"<<N<<"  M"<<M<<endl;
    // construct the corresponding DFA
    for (it= NFA_finalStates.begin(); it!= NFA_finalStates.end(); ++it)
    std::cout << ' ' << *it;
    D = 1;
    DFAstates.push_back(new DFAstate);
    DFAstates[0]->constNFAstates[0] = 1;
    epsilonClosure(0, DFAstates[0]->constNFAstates);
    for (j = 0; j < N; j++)
        if (DFAstates[0]->constNFAstates[j] == 1 && NFA_finalStates.find(
                j) != NFA_finalStates.end())
        {
            DFAstates[0]->finalState = true;
            //cout<<"if is executed"<<endl;
            DFA_finalStates.push_back(0);
            break;
        }else
        {
        //	cout<<"else is executed"<<endl;
        }
    incompleteDFAstates.push(0);
   
    while (!incompleteDFAstates.empty())
    {
        X = incompleteDFAstates.front();
               incompleteDFAstates.pop();
        for (i = 1; i <= M; i++)
        {
        	//cout<<"i is less than M"<<endl;
            NFAmove(DFAstates[X]->constNFAstates, i,
                    DFAstates[X]->transitions[i]);
            epsilonClosure(DFAstates[X]->transitions[i],
                    DFAstates[X]->transitions[i]);
            for (j = 0; j < D; j++)
                if (DFAstates[X]->transitions[i]
                        == DFAstates[j]->constNFAstates)
                {
                    DFAstates[X]->symTransitions[i] = j;
                    break;
                }
            if (j == D)
            {
            	//	cout<<"loop j=D"<<endl;
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
                  //      cout<<"j is less than N "<<endl;
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
    ofstream fout("DFA.txt");
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
    fout.close();
    return 0;
}
