# A_Cazut_Tataie
Proiect SMP Siniuc_Robert 331AB

Proiectul meu are ca rol atentionarea persoanelor din jur in cazul in care o persoana cade.

Ansamblul creat este format din:
-Arduino Mega 2560
-Modul buzzer 
-Accelerometru Mpu-6050
-Modul cu led R-G-B
-Bread-Board
-Cabluri 

<h1> Modul Buzzer  </h1>

Acesta este compus dintr-un buzzer si un tranzistor pnp.
Tranzitorul ne ofera posibilitatea de a controla buzzerul.

<h1> Accelerometru Mpu-6050  </h1>



<h1> Modul cu led R-G-B  </h1>

Modulul R-G-B are in componenta un led RGB si 3 rezistente, aceste componente fiind prezente pe acelasi PCB realizeaza un modul compact si usor de conectat.
Pe fiecare pin (fiecare culoare are cate un pin) este conectat la un semnal PWM, modificand aceste semnale putem controla culoarea ledului.


<h1>Programul urmareste urmatorii pasi</h1>
1.Verifica setarile si initializeaza accelerometrul
2.Incepe citirea fortelor detectate de accelerometru
3a. Aprinde led-ul RGB cu culoarea verde daca fortele detectate sunt sub 5 Newtoni 
3b. Aprinde led-ul RGB cu culoarea galben daca fortele detectate sunt intre 5 si 15 Newtoni
3c. Aprinde led-ul RGB cu culoarea mov daca fortele detectate sunt intre 15 si 20 Newtoni
3d. In cazul in care forta detectata trece de 20 de Newtoni se apeleaza functia de ALARMA, aceasta porneste modulul de buzzer si aprinde succesiv ledul cu culorile rosu si albastru (asteptam un timp inainte sa reincepem sa verificam accelerometrul lasand astfel timp persoanei sa se ridice)


