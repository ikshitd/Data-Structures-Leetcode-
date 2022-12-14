#include <bits/stdc++.h> 
using namespace std; 

#define int long long 
#define double long double

#define vt vector 
#define endl "\n" 
#define all(x) (x).begin() , (x).end() 
#define sz(x) (int)(x).size()
#define FOR(i , a , b) for(int i = (a); i < (b); i++)
#define EACH(x , a) for(auto &x : a) 

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());

const int mxN = 1e5 ; 
const int mod = 1e9 + 7 ;

template <class T> bool ckmin(T &a , T const &b){
	return (b < a ? a = b , 1 : 0);
}

template <class T> bool ckmax(T &a , T const &b){
	return (a < b ? a = b , 1 : 0); 
}

template <class T> void read(T &x){
	cin >> x ;
}

template <class A , class ...T> void read(A &x , T&... t){
	read(x); 
	read(t...); 
}

template <class T> void read(vt <T> &v){
	EACH(x , v){
		read(x);
	}
}
template <class T> void read(vt <vt <T>> &v){
	EACH(x , v){
		EACH(y , x){
			read(y) ;
		}
	}
}
template <class T> void write(T &x){
	cout << to_string(x) << endl ; 
}

template <class A> void write(vt <A> &v){
	EACH(x , v){
		cout << x << " ";
	}
	cout << endl ;
}
template <class A> void write(vt <vt <A>> &v){
	EACH(x , v){
		EACH(y , x){
			cout << y << " " ; 
		}
		cout << endl ;
	}
	cout << endl ;
}

void heapify(vt <int> &v , int i , int n){
	int mxidx = i ;
	int l = 2 * i + 1 ; 
	int r = 2 * i + 2 ; 
	// just until which point our left child will be greater than the parent
	while(l < n and v[l] > v[mxidx]){
		mxidx = l ;
	}
	// just until which point our right child will be greater than the parent 
	while(r < n and v[r] > v[mxidx]){
		mxidx = r ;
	}
	if(mxidx != i){
		swap(v[i] , v[mxidx]) ;
		heapify(v , mxidx , n) ;
	}
}
void heapsort(vt <int> &v , int n){
	// we know that all the leaf nodes are already sorted then to start heapify we must find the first non leaf node and that will be present at index n / 2
	for(int i = n / 2; i >= 0 ; i--){
		heapify(v , i , n) ;
	}
	for(int i = n - 1 ; i > 0 ; i--){
		swap(v[0] , v[i]) ;
		heapify(v , 0 , i);
	}
}
void solve(){
	int n ; 
	cin >> n ;
	vt <int> v (n) ; 
	for(int &val : v){
		cin >> val ;
	}
	heapsort(v , n) ;
	for(auto x : v){
		cout << x << " " ; 
	}
	cout << endl ; 
	return ;
}


int32_t main(){
	ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ; 
	int TET = 1 ; 
	/* read(TET) ; */ 
	FOR(i , 1 , TET + 1){
		solve() ;
	}
	return 0 ;
}


