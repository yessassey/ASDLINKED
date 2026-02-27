#include <iostream>
using namespace std;

// Struktur Node untuk Singly Linked List
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Cetak isi list
void printList(Node* head) {
    cout << "[";
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data;
        if (cur->next) cout << " -> ";
    }
    cout << "]\n";
}

// Bebaskan semua node 
void freeList(Node*& head) {
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

// insert di akhir (end)  
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);  // alokasi + set data, next = nullptr
    if (head == nullptr) {
        // Jika list kosong, node baru menjadi head (kasus ini tetap benar secara umum)
        head = newNode;
        return;
    }
    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newNode; // tautkan sebagai next dari node terakhir
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;

    // --------- 1) Bangun list awal (untuk demonstrasi) ---------
    cout << "Masukkan jumlah elemen awal list: " << flush;
    int n;
    if (!(cin >> n) || n < 0) {
        cout << "Input tidak valid.\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cout << "Masukkan nilai node ke-" << i << ": " << flush;
        int val;
        if (!(cin >> val)) {
            cout << "Input tidak valid.\n";
            freeList(head);
            return 0;
        }
        // Bangun list awal dengan insert di akhir juga (boleh reuse fungsi)
        insertAtEnd(head, val);
    }

    cout << "\nList awal: ";
    printList(head);
    // -------------------------------------------------------------------------------

    // --------- 2) Operasi yang diuji: INSERT DI AKHIR (END) ---------
    cout << "Masukkan nilai yang ingin di-insert ke akhir: " << flush;
    int x;
    if (!(cin >> x)) {
        cout << "Input tidak valid.\n";
        freeList(head);
        return 0;
    }

    insertAtEnd(head, x);
    // ------------------------------------------------------------------

    cout << "List setelah insert di akhir: ";
    printList(head);

    freeList(head);
    return 0;
}
