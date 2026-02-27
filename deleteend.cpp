#include <iostream>
using namespace std;

// Struktur Node
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

// insert di akhir (untuk bangun list awal)
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) { head = newNode; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = newNode;
}

// delete di akhir (end/tail)
bool deleteAtEnd(Node*& head, int& removedValue) {
    if (!head) return false;          // list kosong
    if (!head->next) {
        // hanya 1 elemen
        removedValue = head->data;
        delete head;
        head = nullptr;
        return true;
    }
    // lebih dari 1 elemen: cari node sebelum terakhir
    Node* prev = head;
    while (prev->next && prev->next->next) {
        prev = prev->next;
    }
    Node* last = prev->next;          // node terakhir
    removedValue = last->data;
    prev->next = nullptr;             // putuskan tautan tail lama
    delete last;                      // dealokasi
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;

    // 1) Bangun list awal
    cout << "Masukkan jumlah elemen awal list: " << flush;
    int n;
    if (!(cin >> n) || n < 0) {
        cout << "Input tidak valid.\n";
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        cout << "Masukkan nilai node ke-" << i << ": " << flush;
        int val;
        if (!(cin >> val)) { cout << "Input tidak valid.\n"; freeList(head); return 0; }
        insertAtEnd(head, val);
    }

    cout << "\nList awal: ";
    printList(head);

    // 2) Operasi yang diuji: DELETE DI AKHIR (END/TAIL)
    cout << "Hapus node terakhir? (1 = ya, 0 = tidak): " << flush;
    int confirm;
    if (!(cin >> confirm)) { cout << "Input tidak valid.\n"; freeList(head); return 0; }

    if (confirm == 1) {
        int removed;
        bool ok = deleteAtEnd(head, removed);
        if (!ok) {
            cout << "List kosong. Tidak ada yang dihapus.\n";
        } else {
            cout << "Node terakhir dengan nilai " << removed << " telah dihapus.\n";
        }
    } else {
        cout << "Operasi penghapusan dibatalkan.\n";
    }

    cout << "List sekarang: ";
    printList(head);

    freeList(head);
    return 0;
}