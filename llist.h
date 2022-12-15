using namespace std;

template <class Z>
class List;

template <class W>
   ostream& operator<< (ostream &, const List<W> &);

template <class T>
class Node {
	template <class A>
	friend class List;
	template <class Z>
	friend ostream& operator<<(ostream&, const List<Z>&); 
	public :
	Node(T& t, Node<T>* p) : info(t), berikut(p) { }
	protected :
	T info;
	Node *berikut;
};

template <class T>
class List {
	template <class W>
	friend ostream& operator<<(ostream&, const List<W>& );
	public :
	List() : kepala(0) { }
	~List();
	void sisip(T t);
	int hapus(T& t);
	int kosong() { return (kepala == 0); }
	void cetak();
	protected:
	Node<T>* kepala;
	Node<T>* nodeBaru(T& t, Node<T>* p)
	{ Node<T>* q = new Node<T>(t,p); return q; }
};

template <class T>
ostream& operator<<(ostream& out, const List<T>& k) {
	for (Node<T>* p = k.kepala; p; p=p->berikut) 
	out << p->info << " -> ";
	out << "*\n";
	return out;
}

template <class T>
List<T>::~List() {
	Node<T>* temp;
	for (Node<T>* p = kepala; p;)
	{
	temp = p;
	p = p->berikut;
	delete temp;
	}
}

template <class T>
void List<T>::sisip(T t)
{ 
	cout << t << " masuk list : ";
	Node<T>* p = nodeBaru(t,kepala);
	kepala = p;
}

template <class T>
int List<T>::hapus(T& t)
{
	if (kosong()) return 0; // penghapusan gagal
	t = kepala->info;
	Node<T>* p = kepala;
	kepala = kepala->berikut;
	delete p;
	return 1; // penghapusan sukses
}

template <class T>
void List<T>::cetak()
{
	for (Node<T>* p = kepala; p; p=p->berikut)
	cout << p->info << " -> ";
	cout << "*\n"; 
}

template <class T>
//create function to delete data key from head linked list
T deleteElement(T& head, T& temp, T& hapus,string key,bool posisi_awal) {

	if (posisi_awal==true) {
                temp = temp->next;
                hapus = head;
                head = temp;
                delete hapus;
	}
	else {
                while (temp->next->data!=key) {
                    temp = temp->next;
                }
                hapus = temp->next;
                temp->next = temp->next->next;
                delete hapus;
	}

	temp = head;
	head = temp;
	return head;
}