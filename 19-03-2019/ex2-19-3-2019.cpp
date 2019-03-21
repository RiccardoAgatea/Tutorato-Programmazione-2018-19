#include<iostream>
using namespace std;



void stampaR(int * r, int dim){
  for(int i = 0; i<dim; i++){
	  cout << r[i] << " ";
  }
  cout <<endl;
}


void stampaS(int * s, int dim1, int dim2, int elementi){
	for(int i =0; i<dim1; i++){
		if(i<elementi/dim2){
			cout<< "r"<<i<<":";
			stampaR(s + i*dim2, dim2);
		}else if(i==elementi/dim2 && elementi%dim2>0){
			cout<< "r"<<i<<":";
			stampaR(s + i*dim2, elementi%dim2);
		}
	}
	cout<<endl;
}




int main(){


	int n_ele, lim1,lim2, lim3, X[400];
	cin>>n_ele;
	for(int i=0; i<n_ele; i=i+1)
	   cin>>X[i];
	cin>>lim1>>lim2>>lim3;

	cout<<"start"<<endl;

	int * p=X;


	for(int i=0; i<lim1; i++){
		if(i<n_ele/(lim2*lim3)){
			cout<<"strato"<<i<<endl;
			stampaS(p, lim2, lim3, lim2*lim3);
		}else if(i==n_ele/(lim2*lim3) && n_ele%(lim2*lim3)>0){
			cout<<"strato"<<i<<endl;
			stampaS(p, lim2, lim3, n_ele%(lim2*lim3));
		}
	}

	cout<<"end"<<endl;

}
