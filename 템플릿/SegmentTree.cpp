template<typename T>
struct seg{
    // 0 based index
    int n;T identity;vector<T>tree;
    function<T(T,T)>op;
    seg() {}
    seg(int _n,T _identity,function<T(T,T)>_op)
        :n(_n),identity(_identity),op(_op){tree=vector<T>(2*_n,identity);}
    void upd(int i,T x){
        tree[i+=n]=x;
        for(i>>=1;i>0;i>>=1)tree[i]=op(tree[i<<1],tree[i<<1|1]);
    }
    T qry(int l,int r){
        T ret=identity;
        for(l+=n,r+=n;l<=r;l>>=1,r>>=1){
            if(l&1)ret=op(tree[l++], ret);
            if(~r&1)ret=op(ret,tree[r--]);
        }
        return ret;
    }
};
