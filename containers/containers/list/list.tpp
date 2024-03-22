namespace s21 {

template <class T>
list<T>& list<T>::operator=(const list<T>& other) {
  if (this != &other) {
    while (!empty()) {
      pop_front();
    }
    Node<value_type>* current = other.head;
    while (current) {
      push_back(current->data);
      current = current->next;
    }
  }
  return *this;
}

template <class T>
list<T>& list<T>::operator=(list<T>&& other) noexcept {
  if (this != &other) {
    clear();
    head = other.head;
    tails = other.tails;
    list_size = other.list_size;

    other.head = nullptr;
    other.tails = nullptr;
    other.list_size = 0;
  }
  return *this;
}

template <class T>
void list<T>::clear() {
  while (!empty()) {
    pop_front();
  }
}

template <class T>
typename list<T>::iterator list<T>::insert(list::iterator pos,
                                           list::const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = head;
  } else if (pos == end()) {
    push_back(value);
    pos = tails;
  } else {
    Node<T>* current = pos.current;
    Node<T>* blank = new Node(value);
    blank->next = current;
    blank->prev = current->prev;
    current->prev->next = blank;
    current->prev = blank;
    list_size++;
    return iterator(blank);
  }
  return pos;
}

template <class T>
void list<T>::erase(list::iterator pos) {
  if (pos == end() || empty()) {
    return;
  }
  Node<T>* current = pos.current;
  if (current->prev) {
    current->prev->next = current->next;
  } else {
    head = current->next;
  }
  if (current->next) {
    current->next->prev = current->prev;
  } else {
    tails = current->prev;
  }
  delete current;
  --list_size;
}

template <class T>
void list<T>::push_back(list::const_reference value) {
  auto new_node = new Node<value_type>(value);
  if (!head) {
    head = tails = new_node;
  } else {
    tails->next = new_node;
    new_node->prev = tails;
    tails = new_node;
  }
  ++list_size;
}

template <class T>
void list<T>::pop_back() {
  if (empty()) {
    return;
  }
  Node<T>* temp = tails;
  if (tails->prev) {
    tails = tails->prev;
    tails->next = nullptr;
  } else {
    head = tails = nullptr;
  }
  delete temp;
  --list_size;
}

template <class T>
void list<T>::push_front(list::const_reference value) {
  Node<T>* new_node = new Node<T>(value);
  if (!head) {
    head = tails = new_node;
  } else {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
  ++list_size;
}

template <class T>
void list<T>::pop_front() {
  if (list_size == 0) {
    return;
  }
  if (list_size == 1) {
    delete head;
    head = tails = nullptr;
  } else {
    Node<value_type>* next_head = head->next;
    next_head->prev = nullptr;
    delete head;
    head = next_head;
  }
  --list_size;
}

template <class T>
void list<T>::swap(list<T>& other) {
  std::swap(head, other.head);
  std::swap(tails, other.tails);
  std::swap(list_size, other.list_size);
}

template <class T>
void list<T>::merge(list<T>& other) {
  iterator it1 = begin();
  iterator it2 = other.begin();
  iterator end1 = end();
  iterator end2 = end();

  while (it1 != end1 && it2 != end2) {
    if (*it2 < *it1) {
      insert(it1, *it2);
      ++it2;
    } else {
      ++it1;
    }
  }
  while (it2 != end2) {
    push_back(*it2);
    ++it2;
  }
  other.clear();
}

template <class T>
void list<T>::splice(list::const_iterator pos, list<T>& other) {
  if (other.empty()) {
    return;
  }
  if (this == &other) {
    return;
  }
  auto splice_start = other.head;
  auto splice_end = other.tails;
  auto splice_size = other.size();

  other.head = other.tails = nullptr;
  other.list_size = 0;

  Node<T>* insert_before = pos.current;

  if (insert_before == nullptr) {
    if (empty()) {
      head = splice_start;
    } else {
      tails->next = splice_start;
      splice_start->prev = tails;
    }
    tails = splice_end;
  } else {
    auto insert_after = insert_before->prev;
    if (insert_after == nullptr) {
      head = splice_start;
    } else {
      insert_after->next = splice_start;
      splice_start->prev = insert_after;
    }
    splice_end->next = insert_before;
    insert_before->prev = splice_end;
  }
  list_size += splice_size;
}

template <class T>
void list<T>::reverse() {
  if (list_size <= 1) {
    return;
  }
  auto* current = head;
  Node<value_type>* prevNode = nullptr;
  Node<value_type>* nextNode = nullptr;

  while (current != nullptr) {
    nextNode = current->next;
    current->next = prevNode;
    current->prev = nextNode;
    prevNode = current;
    current = nextNode;
  }

  tails = head;
  head = prevNode;
}

template <class T>
void list<T>::unique() {
  if (head == nullptr || head->next == nullptr) {
    return;
  }
  auto current = head;
  while (current->next != nullptr) {
    if (current->data == current->next->data) {
      auto duplicate = current->next;
      current->next = current->next->next;
      delete duplicate;
      list_size--;
    } else {
      current = current->next;
    }
  }
}

template <class T>
void list<T>::sort() {
  if (list_size <= 1) {
    return;
  }

  for (iterator it1 = begin(); it1 != end(); ++it1) {
    for (iterator it2 = it1; it2 != end(); ++it2) {
      if (*it2 < *it1) {
        std::swap(*it1, *it2);
      }
    }
  }
}

template <class T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args&&... args) {
  for (const auto& arg : {args...}) {
    insert(pos, arg);
  }
  return pos;
}

template <class T>
template <class... Args>
void list<T>::insert_many_back(Args&&... args) {
  for (const auto& arg : {args...}) {
    push_back(arg);
  }
}

template <class T>
template <class... Args>
void list<T>::insert_many_front(Args&&... args) {
  for (const auto& arg : {args...}) {
    push_front(arg);
  }
}

}  // namespace s21