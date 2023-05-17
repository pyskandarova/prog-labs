#include "iostream"
#include "string"

using namespace std;

struct Cocktail {
    string name;
    int amount;
    double cost;
    Cocktail *next;
    
    typedef Cocktail *PCocktail;
    PCocktail Head = NULL;

    PCocktail CreateNode ( string NewName, int NewAmount, double NewCost) {

        Cocktail *NewCocktail = new Cocktail;
        NewCocktail -> name = NewName;
        NewCocktail -> amount = NewAmount;
        NewCocktail -> cost = NewCost;
        NewCocktail -> next = NULL;

        return NewCocktail;
    }

    void AddFirst (Cocktail *&Head, string NewName, int NewAmount, double NewCost){ 

        Cocktail *NewCocktail = new Cocktail;
        NewCocktail -> name = NewName;
        NewCocktail -> amount = NewAmount;
        NewCocktail -> cost = NewCost;
        NewCocktail -> next = Head;
        Head = NewCocktail;


        return;
}

    void AddLast (Cocktail *&Head, string NewName, int NewAmount, double NewCost)
{
        Cocktail *tmp = Head;

        if ( Head == NULL ) {
            AddFirst( Head, NewName, NewAmount, NewCost);
            return; } 
        while ( tmp->next ) tmp = tmp->next;

        Cocktail *NewCocktail = new Cocktail;
        NewCocktail -> name = NewName;
        NewCocktail -> amount = NewAmount;
        NewCocktail -> cost = NewCost;
        NewCocktail -> next = NULL;
        tmp->next = NewCocktail;

        return;
}

int AddAfter(Cocktail *&Head, string NewName, int NewAmount, double NewCost, string NameAfter)

        { if ( Head == NULL )return 1;

        Cocktail *tmp = Head;

        while(tmp != NULL && tmp->name != NameAfter)
    tmp = tmp->next;
        if ( tmp == NULL )return 1;

        Cocktail *NewCocktail = new Cocktail;
        NewCocktail -> name = NewName;
        NewCocktail -> amount = NewAmount;
        NewCocktail -> cost = NewCost;
        NewCocktail->next = tmp->next;
        tmp->next = NewCocktail;
  return 0;
}

int AddBefore( Cocktail *&Head, string NewName, int NewAmount, double NewCost, string NameBefore)

{ if ( Head == NULL )return 1;
  if (Head->name == NameBefore )
    { AddFirst(Head, NewName, NewAmount, NewCost);
    return 0; }

    if ( Head->next == NULL )return 1;

    Cocktail *prev = Head, *tmp = Head->next;

    while(tmp->next!=NULL && tmp->name!=NameBefore)

        { prev = prev->next;
        tmp = tmp->next; }

  if ( tmp->next==NULL && tmp->name!=NameBefore)return 1;

    Cocktail *NewCocktail = new Cocktail;
        NewCocktail -> name = NewName;
        NewCocktail -> amount = NewAmount;
        NewCocktail -> cost = NewCost;
        NewCocktail->next = tmp;
        prev->next = NewCocktail;
  return 0;
}

int DelCocktail( Cocktail *&Head, string DelName)
{ if ( Head == NULL )return 1;
  Cocktail *tmp = Head;

    if ( Head->name == DelName )
        { Head = Head->next;
        delete tmp;
        return 0;}

    if ( Head->next == NULL )return 1;

    Cocktail *prev = Head;
    tmp = Head->next;

    while(tmp->next != NULL && tmp->name != DelName)
       { prev = prev->next;
       tmp = tmp->next; }
    if ( tmp->next==NULL && tmp->name!= DelName)return 1;
  prev->next = tmp->next;
  delete tmp;
  return 0;
}

void PrintList( Cocktail *Head)
{ if ( Head == NULL )
  { cout<<"The list is empty"; return; }
  Cocktail *tmp = Head;
  while(tmp != NULL)
  { cout<<"Cocktail: "<<tmp->name<<
          "\nAmount: "<<tmp->amount<<
          "\nCost: "<<tmp->cost<<"\n\n";
    tmp = tmp->next;
  }
  return;
}
};

int main() {

    Cocktail *list = new Cocktail();

    list -> AddFirst(list, "Chuuya", 1, 3.5);
    list -> AddBefore(list, "Dazai", 2, 3.5, "Chuuya");
    list -> AddAfter(list, "Mori", 3, 3.0, "Dazai");
    list -> AddLast(list, "Koyo", 4, 3.0);
    list -> AddAfter(list, "Yosano", 5, 3.0, "Chuuya");
    list -> DelCocktail(list, "Koyo");

    list -> PrintList(list);

    return 0;
}
