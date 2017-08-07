/*
  1. Добавлять ключ и значение
  2. Получать значение по ключу сложность операции О(1)
  3. Удалять значение по ключу О(1)
  ------
  Если элемент уже есть хэширован, заменить данный элемент
*/

class Hashtable {
  constructor() {
    this.memory = [];
  }

  set(key, value) {
    // 1. Проверить, что данный ключ и значение ранее не был добавлен
  }

  findIndex(key) {
    for (let i = 0; i < this.memory.length; i++) {
      let [hashKey] = this.memory[i];
      if (hashKey === key) return i;
    }
    return -1;
  }
  get(key) {
    return this.memory[key]
  }
}
