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

// insert di akhir (untuk demonstrasi list awal)
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) { head = newNode; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = newNode;
}

// delete di awal (head)
bool deleteAtBegin(Node*& head, int& removedValue) {
    if (!head) return false;               // list kosong → gagal hapus
    Node* del = head;                      // simpan node lama (head lama)
    removedValue = del->data;              // ambil nilainya (opsional, untuk ditampilkan)
    head = head->next;                     // head pindah ke node berikutnya
    delete del;                            // dealokasi node lama
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

    // 2) Operasi yang diuji: DELETE DI AWAL (HEAD)
    cout << "Hapus node pertama? (1 = ya, 0 = tidak): " << flush;
    int confirm;
    if (!(cin >> confirm)) { cout << "Input tidak valid.\n"; freeList(head); return 0; }

    if (confirm == 1) {
        int removed;
        bool ok = deleteAtBegin(head, removed);
        if (!ok) {
            cout << "List kosong. Tidak ada yang dihapus.\n";
        } else {
            cout << "Node pertama dengan nilai " << removed << " telah dihapus.\n";
        }
    } else {
        cout << "Operasi penghapusan dibatalkan.\n";
    }

    cout << "List sekarang: ";
    printList(head);

    freeList(head);
    return 0;
}