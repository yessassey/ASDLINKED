#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

void printList(Node* head) {
    cout << "[";
    for (Node* cur = head; cur; cur = cur->next) {
        cout << cur->data;
        if (cur->next) cout << " -> ";
    }
    cout << "]\n";
}

int length(Node* head) {
    int len = 0;
    for (Node* cur = head; cur; cur = cur->next) ++len;
    return len;
}

void freeList(Node*& head) {
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;

    // Bangun list awal (insert di akhir)
    cout << "Masukkan jumlah elemen awal list (>=2): " << flush;
    int n; 
    if (!(cin >> n) || n < 2) {
        cout << "Input tidak valid atau terlalu sedikit elemen.\n";
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        cout << "Masukkan nilai node ke-" << i << ": " << flush;
        int val; 
        if (!(cin >> val)) { cout << "Input tidak valid.\n"; freeList(head); return 0; }
        Node* nd = new Node(val);
        if (!head) head = nd;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = nd;
        }
    }

    cout << "\nList awal: ";
    printList(head);

    cout << "Masukkan nilai yang ingin di-insert (tengah): " << flush;
    int x; 
    if (!(cin >> x)) { cout << "Input tidak valid.\n"; freeList(head); return 0; }

    int len = length(head);
    cout << "Masukkan indeks i (1.." << (len - 1)
         << ") untuk menyisipkan SETELAH node ke-i: " << flush;
    int i; 
    if (!(cin >> i) || i < 1 || i > len - 1) {
        cout << "Posisi tidak valid untuk 'tengah'.\n";
        freeList(head);
        return 0;
    }

    // MAU ke node ke-i yg mana?
    Node* cur = head;
    for (int k = 1; k < i; ++k) cur = cur->next;

    Node* newNode = new Node(x);
    newNode->next = cur->next;
    cur->next = newNode;

    cout << "List setelah insert di tengah (setelah node ke-" << i << "): ";
    printList(head);

    freeList(head);
    return 0;
}