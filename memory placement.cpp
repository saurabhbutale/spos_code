#include<iostream>
using namespace std;

void bestFit(int n, int pn, string pr[], int size[], int alloc[]) {
    int block[n];
    string fit[pn];
    int select[pn];
    int addr[pn + 1];
    float total = 0;
    float used = 0;

    for (int i = 0; i < n; i++) {
        block[i] = -1;
    }

    for (int i = 0; i < pn; i++) {
        fit[i] = 'E';
    }

    for (int i = 0; i < pn; i++) {
        select[i] = 0;
    }

    addr[0] = 0;

    for (int i = 1; i < pn + 1; i++) {
        addr[i] = addr[i - 1] + alloc[i - 1];
        total = addr[i];
    }

    int p = 0;
    while (p < n) {
        int temp = 0;
        int min = 9999;
        for (int i = 0; i < pn; i++) {
            if (alloc[i] - size[p] >= 0 && alloc[i] - size[p] < min && select[i] != 1) {
                min = (alloc[i] - size[p]);
                temp = i;
            }
        }
        if (temp != 0) {
            fit[temp] = pr[p];
            used = used + size[p];
            block[p] = temp + 1;
            select[temp] = 1;
        }
        p++;
    }

    cout << "\nBEST FIT" << endl;
    cout << "processes" << "\t" << "size" << "\t" << "Partition no." << endl;
    for (int i = 0; i < n; i++) {
        cout << pr[i] << "\t\t" << size[i] << "k\t" << block[i] << endl;
    }

    cout << endl;
    cout << "partition" << "\t\t" << "Allocation" << "\t\t" << "Address" << endl;
    int m = 0;
    while (m < pn + 1) {
        for (int i = m; i < m + 1; i++) {
            if (i < pn) {
                cout << i + 1 << "\t\t\t";
            }
            else {
                cout << "\t\t\t";
            }
        }
        for (int j = m; j < m + 1; j++) {
            if (m < pn) {
                cout << fit[j] << "    [" << alloc[j] << "]\t\t";
            }
            else {
                cout << "\t\t        ";
            }
        }
        for (int k = m; k < m + 1; k++) {
            cout << addr[k] << "";
        }
        cout << endl;
        m++;
    }

    cout << "\n memory used=" << used;
    cout << "\n total memory=" << total;
    cout << "\n Memory utilized= " << used / total << endl;
}

void firstFit(int n, int pn, string pr[], int size[], int alloc[]) {
    int block[n];
    string fit[pn];
    int select[pn];
    int addr[pn + 1];
    float total = 0;
    float used = 0;

    for (int i = 0; i < n; i++) {
        block[i] = -1;
    }

    for (int i = 0; i < pn; i++) {
        fit[i] = 'E';
    }

    for (int i = 0; i < pn; i++) {
        select[i] = 0;
    }

    addr[0] = 0;

    for (int i = 1; i < pn + 1; i++) {
        addr[i] = addr[i - 1] + alloc[i - 1];
        total = addr[i];
    }

    int p = 0;
    while (p < n) {
        for (int i = 0; i < pn; i++) {
            if (alloc[i] >= size[p] && select[i] != 1) {
                fit[i] = pr[p];
                used = used + size[p];
                block[p] = i + 1;
                select[i] = 1;
                break;
            }
        }
        p++;
    }

    cout << "\nFIRST FIT" << endl;
    cout << "processes" << "\t" << "size" << "\t" << "Partition no." << endl;
    for (int i = 0; i < n; i++) {
        cout << pr[i] << "\t\t" << size[i] << "k\t\t" << block[i] << endl;
    }

    cout << endl;
    cout << "partition" << "\t\t" << "Allocation" << "\t\t" << "Address" << endl;
    int m = 0;
    while (m < pn + 1) {
        for (int i = m; i < m + 1; i++) {
            if (i < pn) {
                cout << i + 1 << "\t\t";
            }
            else {
                cout << "\t\t";
            }
        }
        for (int j = m; j < m + 1; j++) {
            if (m < pn) {
                cout << fit[j] << "   [" << alloc[j] << "k]\t\t";
            }
            else {
                cout << "\t\t\t";
            }
        }
        for (int k = m; k < m + 1; k++) {
            cout << addr[k] << "k";
        }
        cout << endl;
        m++;
    }

    cout << "\n memory used=" << used;
    cout << "\n total memory=" << total;
    cout << "\n Memory utilized= " << used / total << endl;
}

void nextFit(int n, int pn, string pr[], int size[], int alloc[]) {
    int block[n];
    string fit[pn];
    int select[pn];
    int addr[pn + 1];
    float total = 0;
    float used = 0;

    for (int i = 0; i < n; i++) {
        block[i] = -1;
    }

    for (int i = 0; i < pn; i++) {
        fit[i] = 'E';
    }

    for (int i = 0; i < pn; i++) {
        select[i] = 0;
    }

    addr[0] = 0;

    for (int i = 1; i < pn + 1; i++) {
        addr[i] = addr[i - 1] + alloc[i - 1];
        total = addr[i];
    }
    int p = 0;
    int temp = 0;
    while (p < n) {
        for (int i = temp; i < pn; i++) {
            if (alloc[i] >= size[p] && select[i] != 1) {
                fit[i] = pr[p];
                used = used + size[p];
                block[p] = i + 1;
                temp = i + 1;
                select[i] = 1;
                break;
            }
        }
        if (temp >= pn) {
            temp = 0;
        }
        p++;
    }

    cout << "\nNEXT FIT" << endl;
    cout << "processes" << "\t" << "size" << "\t" << "partition no." << endl;
    for (int i = 0; i < n; i++) {
        cout << pr[i] << "\t\t" << size[i] << "k\t\t" << block[i] << endl;
    }

    cout << endl;
    cout << "partition" << "\t" << "Allocation" << "\t\t" << "Address" << endl;
    int m = 0;
    while (m < pn + 1) {
        for (int i = m; i < m + 1; i++) {
            if (i < pn) {
                cout << i + 1 << "\t\t";
            }
            else {
                cout << "\t\t";
            }
        }
        for (int j = m; j < m + 1; j++) {
            if (m < pn) {
                cout << fit[j] << "   [" << alloc[j] << "k]\t\t";
            }
            else {
                cout << "\t\t\t";
            }
        }
        for (int k = m; k < m + 1; k++) {
            cout << addr[k] << "k";
        }
        cout << endl;
        m++;
    }

    cout << "\n memory used=" << used;
    cout << "\n total memory=" << total;
    cout << "\n Memory utilized= " << used / total << endl;
}

void worstFit(int n, int pn, string pr[], int size[], int alloc[]) {
    int block[n];
    string fit[pn];
    int select[pn];
    int addr[pn + 1];
    float total = 0;
    float used = 0;

    for (int i = 0; i < n; i++) {
        block[i] = -1;
    }

    for (int i = 0; i < pn; i++) {
        fit[i] = 'E';
    }

    for (int i = 0; i < pn; i++) {
        select[i] = 0;
    }

    addr[0] = 0;

    for (int i = 1; i < pn + 1; i++) {
        addr[i] = addr[i - 1] + alloc[i - 1];
        total = addr[i];
    }

    int p = 0;
    while (p < n) {
        int temp = 0;
        int max = 0;
        for (int i = 0; i < pn; i++) {
            if (alloc[i] - size[p] >= 0 && alloc[i] - size[p] > max && select[i] != 1) {
                max = (alloc[i] - size[p]);
                temp = i;
            }
        }
        if (temp != 0) {
            fit[temp] = pr[p];
            used = used + size[p];
            block[p] = temp + 1;
            select[temp] = 1;
        }
        p++;
    }

    cout << "\nWORST FIT" << endl;
    cout << "processes" << "\t" << "size" << "\t" << "Partition no." << endl;
    for (int i = 0; i < n; i++) {
        cout << pr[i] << "\t\t" << size[i] << "k\t" << block[i] << endl;
    }

    cout << endl;
    cout << "partition" << "\t\t" << "Allocation" << "\t\t" << "Address" << endl;
    int m = 0;
    while (m < pn + 1) {
        for (int i = m; i < m + 1; i++) {
            if (i < pn) {
                cout << i + 1 << "\t\t\t";
            }
            else {
                cout << "\t\t\t";
            }
        }
        for (int j = m; j < m + 1; j++) {
            if (m < pn) {
                cout << fit[j] << "    [" << alloc[j] << "]\t\t";
            }
            else {
                cout << "\t\t        ";
            }
        }


        for (int k = m; k < m + 1; k++) {
            cout << addr[k] << "";
        }
        cout << endl;
        m++;
    }

    cout << "\n memory used=" << used;
    cout << "\n total memory=" << total;
    cout << "\n Memory utilized= " << used / total << endl;
}

int main() {
    cout << "Enter total number of processes" << endl;
    int n;
    cin >> n;
    cout << "Enter total number of partitions" << endl;
    int pn;
    cin >> pn;
    string pr[n];
    int size[n];
    int block[n];
    int partion[pn];
    int alloc[pn];
    int addr[pn + 1];
    char fit[pn]; // Move fit and select declarations to main
    int select[pn];
    float total = 0;
    float used = 0;
    int choice;

    for (int i = 0; i < n; i++) {
        block[i] = -1;
    }

    for (int i = 0; i < pn; i++) {
        partion[i] = i + 1;
        alloc[i] = 0;
    }

    for (int i = 0; i < pn; i++) {
        fit[i] = 'E'; // Fix fit declaration
        select[i] = 0;
    }

    addr[0] = 0;

    for (int i = 1; i < pn + 1; i++) {
        addr[i] = addr[i - 1] + alloc[i - 1];
        total = addr[i];
    }

    cout << "Enter memory partition size" << endl;
    for (int i = 0; i < pn; i++) {
        cout << "Enter partition size of partition[" << i + 1 << "]: ";
        cin >> alloc[i];
    }

    cout << "Enter processes" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter pr[" << i + 1 << "]: ";
        cin >> pr[i];
    }

    cout << "Enter processes size" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter size of pr[" << i + 1 << "]: ";
        cin >> size[i];
    }
    

    do
    {
        cout<<"main menu"<<endl;
        cout<<"1.first fit"<<endl;
        cout<<"2.next fit"<<endl;
        cout<<"3.best fit"<<endl;
        cout<<"4.worst fit"<<endl;
        cout<<"enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1: 
            firstFit(n, pn, pr, size, alloc);
            break;

            case 2:
            nextFit(n, pn, pr, size, alloc);
            break;
            case 3:
            bestFit(n, pn, pr, size, alloc);
            break;

            case 4:
            worstFit(n, pn, pr, size, alloc);
            break;
        }
    } while (choice!=5);
    return 0;
}
