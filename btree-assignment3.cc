#include <iostream>
#include <queue>
using namespace std;

struct node{
    node( int, node*, node*);
	int c;
	node* left;
	node* right;
	
	//bool operator<(conc node &rhs) conc{
	//	return ( c < rhs.c );
	//}
};

node::node(int x, node* l=0, node* r=0){
    c=x;
    left=l;
    right=r;
}

void prewalk(node* nd){
    if (nd != 0){
        if (nd->left != 0 || nd->right != 0){
            cout<<nd->c;
            prewalk(nd->left);
            prewalk(nd->right);
        }
        else{
            if (nd->left == 0){
                cout<<nd->c;
            }

            
        }
    }
                
}
void postwalk(node* nd){
    if (nd != 0){
        if (nd->left != 0 || nd->right != 0){
            postwalk(nd->left);
            postwalk(nd->right);
            cout<<nd->c;
        }
        else{
            cout<<nd->c;
        }
    }
        


}
void inwalk(node* nd){
    if (nd ->left == 0){
        cout<<nd->c;
        return;
    }
    else{
        inwalk(nd->left);
        cout<<nd->c;
        inwalk(nd->right);
        
    }
    

}

void breadthwalk(node* nd) {
    if (nd != nullptr) {
        queue<node*> nodes;
        nodes.push(nd);

        while (!nodes.empty()) {
            node* current = nodes.front();
            nodes.pop();

            cout << current->c;

            if (current->left != 0) {
                nodes.push(current->left);
            }
            if (current->right != 0) {
                nodes.push(current->right);
            }
        }
    }
}

/* must pass nd by ref since we may need to insert at the
root node and hence change the root addr */
void insert(node* &nd, int c){  // inserts with order
    if (nd == 0){
        nd = new node(c,0,0);
        return;
    }
    
    
    if (nd->left != 0 || nd->right != 0){
            
        if (nd->c >= c){
            insert(nd->left,c);
        }
        else{
            insert(nd->right,c);
        }
    }
    else{
        if (nd->c > c){
            nd->left = new node(c);
        }
        else{
            nd->right = new node(c);
        }
    }

}


	
void btfree(node* root){ //which order should deleting be: (pre, in, post ) only one of them will work
    
    if (root->left == 0){
        delete root;
    }
    



}



int main(){

	const int iarray[7] = {4,2,6,1,3,5,7};
	node* root=0;

	int x;
	for (x=0; x < 7 ; x++)
	{
        cout<<'a'<<endl;
		insert(root, iarray[x]);
		//walk(root);
		//cout<<endl;
	}
	cout<<"prewalk"<<endl;
	prewalk(root);
	cout<<endl;
	cout<<"postwalk"<<endl;
	postwalk(root);
	cout<<endl;
	cout<<"inwalk"<<endl;
	inwalk(root);
	cout<<endl;
    cout<<"breathwalk"<<endl;
    breadthwalk(root);
    cout<<endl;
	
	btfree(root);
	return (0);
}

