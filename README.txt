GHEORGHE LUMINITA-GABRIELA, grupa 312, seria CB
TEMA 1

CONSTRUIREA SI CITIREA STRUCT-urilor


	Dupa declararea bibliotecilor necesare utilizarii functiilor din cod, urmeaza declararea structurilor in care vor fi stocate diferite date.
	Astfel, pentru stocarea IP-urilor 1 si 2, a mastii 2, cat si ale adreselor de retea corespunzatoare IP-urilor 1 si 2, 
care vor fi calculate ulterior, cat si pentru lucrul cu acestea, se declara structura ,,adress'' ce primeste 4 variabile de tip unsigned int(a,b,c,d), reprezentand cate un byte.
	Pentru stocarea celor N adrese de retea, cat si pentru lucrul cu acestea, se declara structura ,,network"
ce primeste 5 variabile de tip unsigned int(a, b, c, d si e), primele 4 variabile reprezentand cate un byte 
al adresei IP, ultima variabila reprezentand numarul bitilor setati din masca de retea, despartita de adresa IP 
printr-un slash(/).
	Prin functia void read_adress, ce primeste ca parametri 4 pointeri de tip int ce puncteaza catre adresele din memorie
ale fiecarui byte component dintr-o anumita adresa IP, adresa de retea sau masca(toate avand acelasi format: 4 bytes separati printr-un punct), se realizeaza cititrea de la tastatura
a adreselor IP, a adreselor de retea si a mastilor.
	Prin functia void read_network, ce primeste ca parametri 5 pointeri de tip int ce puncteaza catre adresele din memorie 
ale fiecarui byte component dintr-o adresa IP, cat si catre un numar ce reprezinta numarul de biti setati ai mastii de retea(adresa IP fiind separata de numarul de biti setati printr-un slash(/)),
se realizeaza citirea de la tastatura a celor N adrese de retea continute de fiecare set de date.


FUNCTIA MAIN


	In functia main are loc declararea struct adress de masca 1, o masca oarecare construita ulterior, IP1, IP2, a adreselor de retea 1 si 2.
	Tot in aceasta functie se declara masca2(reprezentand un numar intreg si anume numarul de biti de 1 setati), functia task6_checker care va fi de tipul bool, cat si numarul de seturi de date din fiecare fisier de intrare, care va fi si citit ulterior.
	Pentru citirea fiecarui set de date, am utilizat o structura repetitiva ,,for", care va parcurge fiecare set de date de la numarul 0 pana la cel de linii(number_lines). Pentru fiecare set de date, se vor citi MSK_1, MSK_2, IP_1, IP_2, numarul N si N adrese de retea.
	De asemenea functia main contine:
-afisarea numarului de seturi de date
-afisarea task-ului 0
-initializarea variabilei mask(MSK_2 in format zecimal)
-afisarea task-ului 1
-calcului adreselor de retea a IP-urilor 1 si 2 cu ajutorul task-ului 3
-apelul la celelalte functii ce rezolva task-urile temei cu diferiti parametri(task 3, task 4, task 5, task 6, task 7, task 8 si task 9)

TASK 0

	Este format in functia main, prin afisarea IP-ului 1 si a mastii 2, separate prin caracterul slash(/)

TASK 1

	Este creat cu ajutorul a doua functii:

1. 	Functia struct adress task 1, care va primi ca parametru o masca, si returneaza o variabila de tip struct adress:

-in variabila 'result' se va stoca masca 2 in format zecimal
-declararea celor 4 bytes continuti de masca (byte1, byte2, byte3 si byte 4)
-aux  si aux2 sunt utilizate pentru operatiile pe biti
-variabila rest este egala cu restul impartirii mastii 2 la 8, variabila ce contorizeaza numarul bitilor de 1 ce vor preceda numarul de bytes completi de 1(care au valoarea 255)
-variabila completed este egala cu numarul de intregi care se formeaza la impartirea mastii2 la 8, variabila ce contorizeaza numarul de bytes completati doar cu biti de 1 (255 in zecimal)
-se parcurg apoi cazurile in care sunt completati numai cu biti de 1, pe rand, unul, doi, trei si respectiv cei 4 bytes ai mastii. Byte-ul ce succede cei 1,2,3 sau 4 bytes completati numai cu biti de 1, este completat cu biti de 1, atatia cat indica variabila rest, incepand cu pozitia 7
-in cazul in care niciun byte nu este completat doar cu biti de 1, byte-ul se completeaza succesiv cu biti de 1 incepand cu poziia 7
-stocare mastii construite anterior se realizeaza in variabila result ce este de tip struct adress, fiecare byte al mastii(result.a, result.b, result.c, result.d) fiind reprezentat de byte_1, byte_2, byte_3, respectiv byte_4

2.	Functia void print_task1 ce primeste ca parametru o variabila de tip struct si nu returneaza nimic:

-functia printeaza MSK_2 in formati zecimal


TASK 2

	Pentru realizarea task-ului 2 se foloseste functia turnOctal care primeste ca parametru un numar intreg si returneaza o variabila de tip intreg. Functia realizeaza conversia unui numar in baza 8 si returneaza acest numar.
	Intr-o alta functie, void task2, ce primeste ca parametru o variabila de tip struct, se afiseaza conversia mastii in octal utilizand functia turnOctal, cat si conversia mastii in hexazecimal, utilizand facilitate printf-ului,  care permit afisarea unui numar in baza 16, utilizand caracterul ,,%x"

TASK 3

	Se utilizeaza functia void print_task3, care nu returneaza niciun tip de variabila, si primeste ca parametri o adresa IP si o masca. Functia afiseaza adresa de retea, facand SI logic intre fiecare byte al mastii si fiecare byte al adresei IP

TASK 4

	Se utilizeaza functia void task4, care nu returneaza niciun tip de variabila, si primeste ca parametri o adresa IP si o masca. Functia afiseaza adresa de broadcast, facand SAU logic intre fiecare byte al mastii si fiecare byte al adresei IP

TASK 5

	Se utilizeaza functia void task5, care nu returneaza niciun tip de variabila si primeste ca parametri doua adrese de retea. Functia verifica daca cele doua adrese de retea sunt egale, comparand byte cu byte, si afisand un mesaj corespunzator.
	La apelul functiei in functia main, se dau ca parametri adresele de retea pentru IP_1 si IP_2, calculate cu ajutorul altei functii. Aceasta este functia struct adress task3, ce primeste ca parametri o adresa IP si o masca de retea si returneaza adresa de retea corespunzatoare.

TASK 6

	Task-ul 6 se rezolva cu ajutorul a doua functii:

1.	Functia task6_checker care este de tipul bool (returneaza doar valorile 1 si 0), si primeste ca parametru un numar intreg, ce va fi reprezentat de fiecare byte al mastii. Aceasta functie verifica corectitudinea numarului intreg, in sensul in care verifica daca in cadrul acestuia exista alternanta bitilor de 1 si 0.
	In cazul in care byte-ul este egal cu 255 sau cu 0, este corect, iar functia returneaza valoarea 1. Altfel, se construieste numarul 'compare', care este alcatuit din bitii consecutivi de '1' din numar. In cazul in care numarul compare este egal cu cel citit, inseamna ca numarul nu are alternanta 0 si 1 in interiorul sau, deci functia returneaza valoarea 1. Altfel, va returna 0.

2.	Functia bool task6, care va primi ca parametru o masca, functie ce verifica cu ajutorul a task6_checker corectitudinea fiecarui byte al mastii. Se afiseaza astfel mesajul corespunzator.

TASK 7

	Task-ul 7 se rezolva cu ajutorul a doua functii:

1.	Functia unsigned int task7_corrector ce primeste ca parametru un numar intreg, fara semn, ce va reprezenta fiecare byte al mastii. Aceasta functie va corecta byte-ul dat ca parametru in sensul in care, daca va contine alternant de biti 0/1, se vor implementa cu 0 bitii ce succed primului bit de zero setat.

2.	Functia void task7, ce primeste ca parametri o masca si un checker. Daca valoare checkerului este 1, va afisa masca, daca aceasta este corecta, fapt verificat la task6. Pe celalalt caz, daca un byte component al mastii prezinta alternanta 0/1, sau nu este 255 sau 0, se va forma un numar nou doar cu bitii de 1 consecutivi, prezenti pana in momentul alternantei, restul bitilor fiind 0.

TASK 8

	Se utilizeaza functia void task8, ce primeste ca parametru o adresa IP, sau o masca. Functia afiseaza in binar adresa data ca parametru cu ajutorul functiei turnBinar, care converteste fiecare byte, din baza 10, in baza 2.

TASK 9

	Este utilizata functia void task9, ce primeste ca parametru o adresa IP, N-adresele de retea, si numarul de adrese de retea. Pentru fiecare numar din fiecare adresa de retea, reprezentand bitii de 1 setati pentru masca, se construieste cate o adresa de retea cu adresa IP_2, si cu fiecare masca, cu ajutorul task-urilor 1 si 3. Ulterior, tot cu ajutorul task-urilor 1 si 3, se construiesc si adresele de retea pentru fiecare IP din sirul de N-adrese. Se compara apoi adresa de retea pentru IP_2 si adresele de retea alea celor N adrese, si se stocheaza pozitia adreselelor valide, care apartin aceleiasi retele.
	

COMENTARIU : Pe platforma VMChecker imi pica testul 6, avand in vedere ca pe local imi valideaza toate testele. In plus, si taskul 7 se bazeaza pe taskul 6, si acela ruleaza fara nicio problema si sunt confuza in legatura cu ce se intampla
	


	

	


	
	
