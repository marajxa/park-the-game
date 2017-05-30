/*Names: Sophie Rehrig, Samantha Kacir, Nora Broderick, Clare Allsopp-Shiner
 *Assignment: Final Project
 *Date Due: 13 May 2016
 *
 *This file was written by: Sophie Rehrig
 *
 *Purpose: This program is a game set in Park Science Building. This file is the main file for the Inventory class.
 */

#include "Inventory.h"
#include <iostream>
#include <string>

Inventory::Inventory() {
  data = NULL;
  next = NULL;
  type = -1;
  size = 0;
}

Inventory::~Inventory() {
}

void Inventory::printHold() {
  if (sizeOfI() != 0 && hasVisible()) {
    int count = 1;
    Inventory* current = this;
    for (int i=0;i<size;++i) {
      if (!current->data->isHidden() && current != NULL) {
	std::cout << count << ": " << current->data->getName() << "; ";
	count++;
      }
      current = current->next;
    }
    std::cout << '\n';
  } else {
    std::cout << "Nothing to see here, move along!" << std::endl;
  }
}

void Inventory::add(Item* i) {
  if (data == NULL) {
    data = i;
    type = 0;
    next = NULL;
    size = 1;
  } else {
    Inventory* temp = new Inventory();
    Inventory* current = this;
    temp->add(i);
    size++;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
  }
}

void Inventory::add(Key* k) {
  if (data == NULL) {
    data = k;
    type = 1;
    next = NULL;
    size = 1;
  } else {
    Inventory* temp = new Inventory();
    Inventory* current = this;
    temp->add(k);
    size++;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = temp;
    temp->next = NULL;
  }
}

Inventory* Inventory::remove(Item* i) {
  Inventory* current = next;
  Inventory* temp = this;
  Inventory* prev = this;
  if (data == i) {
    if (next != NULL) {
    temp = next;
    } else {
      temp = this;
    }
    data = NULL;
    next = NULL;
    temp->size = size;
    temp->size--;
    return temp;
  }  else {
    while (current != NULL) {
      if (current->next == NULL) {
	if (current->data == i) {
	  current->data = NULL;
	  prev->next = NULL;
	  size--;
	  return this;
	}
      } else if (current->data == i) {
	current->data = NULL;
	prev->next = current->next;
	current = NULL;
	size--;
	return this;
      }
      prev = current;
      current = current->next;
    }
    return this;
  }
}

Inventory* Inventory::remove(Key* k) {
  Inventory* current = next;
  Inventory* temp = this;
  Inventory* prev = this;
  if (data == k) {
    if(next != NULL) {
      temp = next;
    } else {
      temp = this;
    }
    data = NULL;
    next = NULL;
    temp->size = size;
    temp->size--;
    return temp;
  }  else {
    while (current != NULL) {
      if (current->next == NULL) {
	if (current->data == k) {
	  current->data = NULL;
	  prev->next = NULL;
	  size--;
	  return this;
	}
      } else if (current->data == k) {
	current->data = NULL;
	prev->next = current->next;
	current = NULL;
	size--;
	return this;
      }
      prev = current;
      current = current->next;
    }
    return this;
  }
}

int Inventory::sizeOfI() {
  return size;
}

bool Inventory::isEmpty() {
  if (sizeOfI() == 0) {
    return true;
  }
  return false;
}

Object* Inventory::getFromPos(int pos) {
  Inventory* current = this;
  int i=1;
  while (i<pos) {
    if (!(data->isHidden())) {
      current = current->next;
    }else {
      std::cout << "hidden!" << std::endl;
      current = current->next;
      i--;
    }
    i++;
  }
  return current->data;
}

int Inventory::pain() {
  return 37;
}

bool Inventory::hasVisible() {
  int count = 0;
  Inventory* current = this;
  for (int i=0;i<size;++i) {
    if (!current->data->isHidden()) {
      count++;
    }
    current = current->next;
  }
  if (count > 0) {
    return true;
  } else {
    return false;
  }
}

