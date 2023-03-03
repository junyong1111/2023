#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int number = 0;
    int snake_bird = 0;

    cin >> number >> snake_bird;
    vector<int>v(number, 0);

    for(int i = 0; i< number; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for(int i = 0; i < number; i++)
    {
        if (v[i] <= snake_bird){
            snake_bird++;
        }
    }
    cout << snake_bird << "\n";
    return 0;
}