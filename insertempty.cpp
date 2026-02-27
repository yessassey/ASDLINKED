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

// Bebaskan memori
void freeList(Node*& head) {
    Node* cur = head;
    while (cur) {
        Node* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr; // empty list

    // PErintah untuk user saat program dijalankan
    int x;
    cout << "Masukkan nilai untuk node pertama (integer): ";
    cin >> x;

    if (!cin) {
        cout << "Input tidak valid.\n";
        return 0;
    }

    // Insert ke empty list
    head = new Node(x);

    cout << "List setelah insert awal: ";
    printList(head);

    freeList(head);
    return 0;
}