import math

def add_to_list(zap_list, znach):
    zap_list.append(znach)

# -- Задача 1 --

print("-"*20, "\nЗадача 1:\n", "-"*20)

with open('text.txt', 'r', encoding="utf-8") as file:
    text = file.read()

reserved_vords = input("Введи зарезервовані слова: ").split()
for word in reserved_vords:
    word = word.lower()
    text = text.replace(word, word.upper())

print(f"Зімінений текст: \n{text}")

with open('result.txt', 'w', encoding="utf-8") as file:
    file.write(text)

# -- Задача 2 --

print("-"*20, "\nЗадача 2:\n", "-"*20)

try:
    a = float(input("Введи число: "))
except ValueError:
    print("Помилка: введено не число.")
list_1 = []
list_2 = []
list_3 = []
list_4 = []
x = 40

try:
    while x <= 63:
        add_to_list(list_1, math.sin(x-a)*math.cos(a+x))
        add_to_list(list_2, math.tan(math.sin(x)-4*(a-math.cos(x))))
        add_to_list(list_3, a-x*math.cos(a-x)+12*x)
        add_to_list(list_4, x*a+a*math.sin(x))

        x += 1.75
except Exception as e:
    print(f"Помилка: {e}")

print(f"Функція 1: {list_1}")
print(f"Функція 2: {list_2}")
print(f"Функція 3: {list_3}")
print(f"Функція 4: {list_4}")

with open('zavd2.bin', 'wb') as file:
    file.write(f"Функція 1: {list_1}\n".encode('utf-8'))
    file.write(f"Функція 2: {list_2}\n".encode('utf-8'))
    file.write(f"Функція 3: {list_3}\n".encode('utf-8'))
    file.write(f"Функція 4: {list_4}\n".encode('utf-8'))

# -- Задача 3 --

print("-"*20, "\nЗадача 3:\n", "-"*20)

spisok_chisel = []

for i in range(100, 1000):
    b = str(i)
    if b[0] == b[1] == b[2]:
        add_to_list(spisok_chisel, i)

with open('zavd3.bin', 'wb') as file:
    file.write(f"Трицифрові числа з однаковими цифрами: {str(spisok_chisel)}\n".encode('utf-8'))

with open('zavd3.bin', 'rb') as file:
    content = file.read()
    print(content.decode(encoding='utf-8'))
    
final_list = []

for num in spisok_chisel:
    val = int(num)
    add_to_list(final_list, val*10)
with open('zavd3_final.bin', 'wb') as file:
    file.write(f"Трицифрові числа з однаковими цифрами, помножені на 10: {str(final_list)}\n".encode('utf-8'))
with open('zavd3_final.bin', 'rb') as file:
    content = file.read()
    print(content.decode(encoding='utf-8'))