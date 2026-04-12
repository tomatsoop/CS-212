int main() 
{   
    int sum;
    int n = 100;
     // number of operations: n
    // big o notation: O(n)
    for (int i = 0; i < n; i++)
        sum += i;


    // number of operations: 2n
    // big o notation: O(n)

     for (int i = 0; i < n; i++)
        sum += i; 
    for (int i = 0; i < n; i++)
        sum += i;

   
    
    // number of operations: n^2 + 2n
    // big o notation: O(n^2)
     for (int i = 0; i < n; i++)
        for (int j = 0; i < n; j++)
            sum += i + j;

    //  it depends on how it grows with a variable not a
    // constant value 

    // number of operations: n^2 + nlogn + 2n
    // big o notation: O(nlog(n^2))
    for (int i = 0; i < n; i++)
    {
        int x = n;
        while (x >=1)
        {
            x = x / 2;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; i < n; j++)
            for (int k = 0; k < n; k++)
            sum += i + j + k;
    // number of operations: n^3 + n^2 + nlogn + 2n
    // big o notation: O(nlog(n^3))
}