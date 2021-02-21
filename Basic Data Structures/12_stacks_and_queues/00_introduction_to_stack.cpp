#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    cout << st.top() << " " << st.size() << endl;
    st.push(30);
    cout << st.top() << " " << st.size() << endl;
    st.push(40);
    cout << st.top() << " " << st.size() << endl;
    st.pop();
    cout << st.top() << " " << st.size() << endl;
    st.pop();
    cout << st.top() << " " << st.size() << endl;
    st.pop();
    cout << st.top() << " " << st.size() << endl;
    return 0;
}