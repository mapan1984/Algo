template<class T>
class priqueue {
    int n, maxsize;
    T *x;
    void swap(int i, int j)
    {
        T t = x[i];
        x[j] = x[i];
        x[i] = t;
    }
public:
    priqueue(int n)
    {
        maxsize = n;
        x = new T[maxsize+1];
        n = 0;
    }
    void insert(int t)
    {
        int i, p;
        x[++n] = t;
        for(i=n; i > 1 && x[p=i/2] > x[i]; i=p){
            swap(i, p);
        }
    }
    T extractmin()
    {
        int i, c;
        T t = x[1];
        x[1] = x[n--];
        for(i = 1; (c = 2*i) <= n; i = c){
            if(c+1 <=n && x[c+1] < x[c]){
                c++;
            }
            if(x[i] <= x[c]){
                break;
            }
            swap(c, i);
        }
        return t;
    }
}
