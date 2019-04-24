#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
using namespace std;
map<int, int> m;
map<int, int>::iterator it;
vector<int> v;
vector<int> v1;

void RR()
{
    int n; // số tiến trình;
    cout << "Nhap so tien trinh: ";
    cin >> n;
    int a[n + 1]; // mảng lưu thời gian xuất hiện
    int b[n + 1]; // mảng lưu thời gian thực đang chạy cho đến khi chạy hết tiến trình
    int c[n + 1]; // mảng lưu thời gian tồn tại
    int d[n + 1];
    int e[n + 1];
    int element_a = 0, element_b = 0, element_d = 0;
    int time = 0;
    int sum = 0;
    int thuchien, xuathien;
    int R;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p;
        cout << "Process P" << i + 1 << ":" << endl;
        cout << "Thoi gian thuc hien: ";
        cin >> thuchien;
        cout << "Thoi gian xuat hien: ";
        cin >> xuathien;
        a[element_a] = xuathien;
        d[element_a] = thuchien;
        element_a++;
        p = make_pair(xuathien, thuchien);
        m.insert(p);
    }
    cout << "Nhap R: ";
    cin >> R;
    cout << endl;
    cout << setw(10) << "Process" << setw(20) << "Time t/hien" << setw(20) << "Time x/hien" << endl;
    for (int i = 0; i < element_a; i++)
    {
        for (it = m.begin(); it != m.end(); it++)
        {
            if (a[i] == (*it).first)
            {
                cout << setw(9) << "P" << i + 1;
                cout << setw(20) << (*it).second << setw(20) << (*it).first;
                cout << endl;
                break;
            }
        }
    }
    cout << "_________________________________________________________________________________________________" << endl;
    cout << "SO DO Grantt: " << endl;
    cout << "(0) ";
    int z = 0;
    while (1)
    {
        int min1 = 0;
        int min2 = 9999999;
        int dal = 0;
        for (it = m.begin(); it != m.end(); it++)
        {
            if ((*it).first <= time)
            {
                v.push_back((*it).second);
                v1.push_back((*it).first);
                min1 = (*it).first;
                break;
            }
        }
        m.erase(min1);

        for (int i = 0; i < element_a; i++)
        {
            if (a[i] == v1[0])
            {
                if (v[0] <= R)
                {
                    time += v[0];
                    b[i] = time;
                    c[i] = d[i] + v1[0];
                    for (it = m.begin(); it != m.end(); it++)
                    {
                        if ((*it).first < time)
                        {
                            v.push_back((*it).second);
                            v1.push_back((*it).first);
                            min1 = (*it).first;
                            break;
                        }
                    }
                    m.erase(min1);
                    v.erase(v.begin());
                    v1.erase(v1.begin());
                }
                else
                {
                    time += R;
                    v[0] -= R;
                    for (it = m.begin(); it != m.end(); it++)
                    {
                        if ((*it).first < time)
                        {
                            v.push_back((*it).second);
                            v1.push_back((*it).first);
                            min1 = (*it).first;
                            break;
                        }
                    }
                    m.erase(min1);
                    v.push_back(v[0]);
                    v.erase(v.begin());
                    v1.push_back(v1[0]);
                    v1.erase(v1.begin());
                }

                cout << "|P" << i + 1 << "| (" << time << ") ";

                break;
            }
        }
        if (v.empty())
            break;

        //m.erase(min1);
    }
    cout << endl
         << endl
         << "Thoi gian cho cua cac tien trinh: " << endl;
    for (int i = 0; i < element_a; i++)
    {
        cout << "Thoi gian cho P" << i + 1 << ": " << b[i] - c[i] << endl;
        sum += b[i] - c[i];
    }
    cout << "Thoi gian cho trung binh: " << ((float)sum / (float)n) << endl;
}

int main()
{
    RR();
    return 0;
}