#include<bits/stdc++.h>
using namespace std;
#define N1 1000;
#define N2 2000;
#define N3 3000;
#define N4 4000;
int n=3;
int k=0;
void print_matrix(int a[][3]) {
    cout<<"--------------\n";
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"--------------\n";
}
 
bool match(int present[][3],int goal[][3]) {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
        if(present[i][j]!=goal[i][j])
            return false;
        }
    }
    return true;
}
 
void swap(int a[][3],int c_r,int c_c,int r,int c) {
    int k=a[c_r][c_c];
    a[c_r][c_c]=a[r][c];
    a[r][c]=k;
}
 
void solver(int initial[][3],int goal[][3],int c_r,int c_c) {
    if(match(initial,goal)==true) {
        print_matrix(initial);
        k=1;
        return;
    }
    else {
        if(c_r==0 && c_c==0) {
            swap(initial,0,0,1,0);
            print_matrix(initial);
            solver(initial,goal,1,0);
            if(k==1) {
                return;
            }
            swap(initial,0,0,0,1);
            solver(initial,goal,0,1);
            if(k==1) {
                return;
            }
        }
        else if(c_r==0 &&c_c==1) {
            swap(initial,0,1,0,0);
            print_matrix(initial);
            solver(initial,goal,0,0);
            if(k==1) {
                return;
            }
            swap(initial,0,1,0,2);
            solver(initial,goal,0,2);
            if(k==1) {
                return;
            }
            swap(initial,0,1,1,1);
            solver(initial,goal,1,1);
            if(k==1) {
                return;
            }
 
        }
        else if(c_r==0 &&c_c==2) {
            swap(initial,0,2,0,1);
            print_matrix(initial);
            solver(initial,goal,0,1);
            if(k==1) {
                return;
            }
            swap(initial,0,2,1,2);
            solver(initial,goal,1,2);
            if(k==1) {
                return;
            }
        }
        else if(c_r==1 &&c_c==0) {
            swap(initial,1,0,1,1);
            print_matrix(initial);
            solver(initial,goal,1,1);
            if(k==1) {
                return;
            }
            swap(initial,1,0,0,0);
            solver(initial,goal,0,0);
            if(k==1) {
                return;
            }
            swap(initial,1,0,2,0);
            solver(initial,goal,2,0);
            if(k==1) {
                return;
            }
        }
        else if(c_r==1 &&c_c==1) {
            swap(initial,1,1,2,1);
            print_matrix(initial);
            solver(initial,goal,2,1);
            if(k==1) {
                return;
            }
            swap(initial,1,1,0,1);
            solver(initial,goal,0,1);
            if(k==1) {
                return;
            }
            swap(initial,1,1,1,0);
            solver(initial,goal,1,0);
            if(k==1) {
                return;
            }
        }
        else if(c_r==1 &&c_c==2) {
            swap(initial,1,2,0,2);
            print_matrix(initial);
            solver(initial,goal,0,2);
            if(k==1) {
                return;
            }
            swap(initial,1,2,1,1);
            solver(initial,goal,0,0);
            if(k==1) {
                print_matrix(initial);
                return;
            }
        }
        else if(c_r==2 &&c_c==0) {
            swap(initial,2,0,1,0);
            print_matrix(initial);
            solver(initial,goal,1,0);
            if(k==1) {
            return;
            }
            swap(initial,2,0,2,1);
            solver(initial,goal,2,1);
            if(k==1) {
                print_matrix(initial);
                return;
            }
        }
        else if(c_r==2 &&c_c==1) {
            swap(initial,2,1,2,0);
            print_matrix(initial);
            solver(initial,goal,2,0);
            if(k==1) {
                return;
            }
            swap(initial,2,1,1,1);
            solver(initial,goal,1,1);
            if(k==1) {
                print_matrix(initial);
                return;
            }
            swap(initial,2,1,2,2);
            solver(initial,goal,2,2);
            if(k==1) {
                print_matrix(initial);
                return;
            }
        }
        else if(c_r==2 &&c_c==2) {
            swap(initial,2,2,1,2);
            print_matrix(initial);
            solver(initial,goal,1,2);
            if(k==1) {
                print_matrix(initial);
                return;
            }
            swap(initial,2,2,2,1);
            solver(initial,goal,2,1);
            if(k==1) {
                print_matrix(initial);
                return;
            }
        }
    }
    for (int i = 0; i < 100000; i++) {
        cout << "";
    }
}
 
int main() {
    int initial[][3] = {{1,2,3},{4,5,0},{6,7,8}};
    int goal[][3] = {{4,1,2},{5,7,3},{0,6,8}};
    
    cout<<"Inital Matrix :\n";
    print_matrix(initial);
    
    cout<<"final Matrix :\n";
    print_matrix(goal);
    
    cout<<"After Solving :\n";
    cout<<"Sequence in reverse Order\n";
    solver(initial,goal,1,2);
}
