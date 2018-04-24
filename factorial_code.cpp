#include <iostream>
#include <stdlib.h>

using namespace std;



typedef struct node Node;

struct node {
	char data;
	Node *next;
	Node *prev;
};



Node *create (){
	
	Node *nev;
	nev = new (Node);
	cout << "give the value";
	cin >> (nev-> data);
	nev->next = NULL;
	nev->prev = NULL;
	
	return nev;
}



Node *createzero (){
	
	Node *nev;
	nev = new (Node);
	nev->data = '0';
	nev->next = NULL;
	nev->prev = NULL;
	
	return nev;
}



Node *createone (){
	
	Node *nev;
	nev = new (Node);
	nev->data = '1';
	nev->next = NULL;
	nev->prev = NULL;
	
	return nev;
}



void addlast (Node **head, Node **tail){
	
	Node *tmp = create();
	
	if (*head == NULL)
		*head = tmp;
	else{
		Node *pom = *head;
		while (pom->next != NULL)
			pom = pom->next;
		pom->next = tmp;
		tmp->prev = pom;
	}
	
	*tail = tmp;
}



Node *addfirstzero (Node **head, Node **tail){
	
	Node *tmp = createzero();
	
	if (*tail == NULL)
		*tail = tmp;
	else{
		Node *pom = *tail;
		while (pom->prev != NULL)
			pom = pom->prev;
		pom->prev = tmp;
		tmp->next = pom;
	}
	
	*head = tmp;
	
	return *head;
}



Node *addlastzero (Node **head, Node **tail){
	
	Node *tmp = createzero();
	
	if (*head == NULL)
		*head = tmp;
	else{
		Node *pom = *head;
		while (pom->next != NULL)
			pom = pom->next;
		pom->next = tmp;
		tmp->prev = pom;
	}
	
	*tail = tmp;
	
	return *tail;
}



void deleteall (Node **head){
	
	if (*head == NULL)
	cout << "empty!";
	
	else{
		Node *pom = *head;
		while (pom != NULL){
			*head = pom->next;
			delete (pom);
			pom = *head;
		}
	}
}



void showall (Node *head){
	
	if (head == NULL)
	cout << "empty!";
	
	else{
		Node *pom = head;
		while (pom != NULL){
			cout << pom->data;
			pom = pom->next;
		}
	}
}



int countall (Node *head){
	
	int i;
	
	if (head == NULL)
	i = 0;
	
	else{
		Node *pom = head;
		i = 1;
		while (pom->next != NULL){
			i++;
			pom = pom->next;
		}
	}
	
	return i;
}



Node *moveleft (Node **current){
	
	*current = (*current)->prev;
	
	return *current;
}



Node *moveright (Node **current){
	
	*current = (*current)->next;
	
	return *current;
}



void rewriteall (Node **head_z, Node **tail_do, Node **head_do){
	
	if (*head_z == NULL)
	cout << "empty!";
	
	else{
		Node *pom = *head_z;
		while (pom != NULL){
			
			addlastzero (&*head_do, &*tail_do);
			
			(*tail_do)->data = pom->data;
			
			pom = pom->next;
		}
	}
}



void dodaj (Node **tail_liczba, Node **tail_wynik, Node **head_wynik){
	
	Node *current_liczba = *tail_liczba;
	Node *current_wynik = *tail_wynik;
	Node *nadmiar = createzero();
		
	while (current_liczba != NULL){
	
		int a1 = current_liczba->data - 48;
		
		if (current_wynik != NULL);
		else
		current_wynik = addfirstzero (&*head_wynik, &*tail_wynik);
		
		int a2 = current_wynik->data - 48;
		int a3 = nadmiar->data - 48;
		int wynik = a1 + a2 + a3;
	
		if (wynik <= 9){
			
			current_wynik->data = wynik + 48;
			nadmiar->data = '0';
		}
		
		else{
			
			current_wynik->data = wynik - 10 + 48;
			nadmiar->data = '1';
		}
		
		current_liczba = moveleft (&current_liczba);
		current_wynik = moveleft (&current_wynik);
	}
	
	while (nadmiar->data == '1'){
		
		if (current_wynik != NULL);
		else
		current_wynik = addfirstzero (&*head_wynik, &*tail_wynik);
		
		int a2 = current_wynik->data - 48;
		int a3 = nadmiar->data - 48;
		int wynik = a2 + a3;
	
		if (wynik <= 9){
			
			current_wynik->data = wynik + 48;
			nadmiar->data = '0';
		}
		
		else{
			
			current_wynik->data = wynik - 10 + 48;
			nadmiar->data = '1';
		}

		current_wynik = moveleft (&current_wynik);
	}

	delete (nadmiar);

}



void dodajjeden (Node **tail_wynik, Node **head_wynik){
	
	Node *head_liczba = createone();
	Node *tail_liczba = head_liczba;
	Node *current_liczba = tail_liczba;
	
	Node *current_wynik = *tail_wynik;
	Node *nadmiar = createzero();
		
	while (current_liczba != NULL){
	
		int a1 = current_liczba->data - 48;
		
		if (current_wynik != NULL);
		else
		current_wynik = addfirstzero (&*head_wynik, &*tail_wynik);
		
		int a2 = current_wynik->data - 48;
		int a3 = nadmiar->data - 48;
		int wynik = a1 + a2 + a3;
	
		if (wynik <= 9){
			
			current_wynik->data = wynik + 48;
			nadmiar->data = '0';
		}
		
		else{
			
			current_wynik->data = wynik - 10 + 48;
			nadmiar->data = '1';
		}
		
		current_liczba = moveleft (&current_liczba);
		current_wynik = moveleft (&current_wynik);
	}
	
	while (nadmiar->data == '1'){
		
		if (current_wynik != NULL);
		else
		current_wynik = addfirstzero (&*head_wynik, &*tail_wynik);
		
		int a2 = current_wynik->data - 48;
		int a3 = nadmiar->data - 48;
		int wynik = a2 + a3;
	
		if (wynik <= 9){
			
			current_wynik->data = wynik + 48;
			nadmiar->data = '0';
		}
		
		else{
			
			current_wynik->data = wynik - 10 + 48;
			nadmiar->data = '1';
		}

		current_wynik = moveleft (&current_wynik);
	}

	delete (nadmiar);
	deleteall (&head_liczba);

}



void pomnoz (Node **tail_liczba, Node **head_liczba, Node **tail_wynik, Node **head_wynik){
	
	Node *current_liczba = *tail_liczba;
	Node *head_liczba_pom = NULL;
	Node *tail_liczba_pom = NULL;
	rewriteall (&*head_liczba, &tail_liczba_pom, &head_liczba_pom);
	
	Node *current_wynik = *tail_wynik;
	Node *head_wynik_pom = NULL;
	Node *tail_wynik_pom = NULL;
	
	int licznik = 0;
		
	while (current_wynik != NULL){
		
		int i = current_wynik->data - 48;
		
		while (i > 0){
			dodaj (&tail_liczba_pom, &tail_wynik_pom, &head_wynik_pom);
			i--;
		}
		
		current_wynik = moveleft (&current_wynik);
		tail_liczba_pom = addlastzero (&head_liczba_pom, &tail_liczba_pom);
	}
	
	
	deleteall (&*head_wynik);
	*head_wynik = head_wynik_pom;
	*tail_wynik = tail_wynik_pom;
	
	deleteall (&head_liczba_pom);
	
}
	





int main (void){
	
	cout << "Licze silnie. Podaj n: ";
	int n;
	cin >> n;

	if (n < 0){
		
		cout << endl << "Error - liczba ujemna!";
		
	}
	
	else if (n == 0){
		
		cout << endl << "Twoja silnia 0! to: 1";
		cout << endl;
		
	}
	
	else{
		
		Node *head_liczba = NULL, *tail_liczba = NULL, *head_wynik = NULL, *tail_wynik = NULL;
		
		head_liczba = createone();
		tail_liczba = head_liczba;
		head_wynik = createone();
		tail_wynik = head_wynik;
		
		int licznik = 1;
		
		while (licznik <= n){
			
			pomnoz (&tail_liczba, &head_liczba, &tail_wynik, &head_wynik);
			dodajjeden (&tail_liczba, &head_liczba);
			licznik++;
			
		}
		
		cout << endl << "Twoja silnia " << n << "! to: ";
		showall(head_wynik);
		cout << endl;
		
	}
	
	system ("pause");
	return 0;
}


	
