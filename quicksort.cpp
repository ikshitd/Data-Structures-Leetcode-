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

int partition(vt <int>&v , int start , int ending){
	int pivot = v[ending] ; 
	int i = start - 1 ; 
	for(int j = start ; j < ending ; j++){
		if(v[j] < pivot){
			i += 1 ; 
			swap(v[i] ,v[j]) ;
		}
	}
	swap(v[i + 1] , v[ending]) ;
	return i + 1 ;
}
void quicksort(vt <int> &v , int start , int ending){
	if(start >= ending){
		return ;
	}
	int pi = partition(v , start , ending) ; 
	quicksort(v , start , pi - 1) ; 
	quicksort(v , pi + 1 , ending) ;
}

void solve(){
	int n ; 
	cin >> n ; 
	vt <int> v (n) ; 
	for(int &val : v){
		cin >> val ;
	}
	quicksort(v , 0 , n - 1) ;
	for(int &val : v){
		cout << val << " " ;  
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


