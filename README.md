# A_Cazut_Tataie
Proiect SMP Siniuc Robert-Valentin 331AB

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

<h1> Modulul cu Accelerometru Mpu-6050  </h1>

Componenta de accelerometru din modulul folosit se baseaza pe principiul piezoelectric ar unui material. 
Astfel in miscarea modului, materialul estee comprimat sau dilatat si astfel produce un curent electric proportional cu forta aplicata.
Afland acceleratia modulului putem determina forta aplicata aspura lui si astfel suntem capabil sa detectam caderea unei persoane

<h1> Modul cu led R-G-B  </h1>

Modulul R-G-B are in componenta un led RGB si 3 rezistente, aceste componente fiind prezente pe acelasi PCB realizeaza un modul compact si usor de conectat.
Pe fiecare pin (fiecare culoare are cate un pin) este conectat la un semnal PWM, modificand aceste semnale putem controla culoarea ledului.


<h1>Programul urmareste urmatorii pasi</h1>
<ul>
<li>1.Verifica setarile si initializeaza accelerometrul</li>
<li>2.Incepe citirea fortelor detectate de accelerometru</li>
<li>3a. Aprinde led-ul RGB cu culoarea verde daca fortele detectate sunt sub 5 Newtoni </li>
<li>3b. Aprinde led-ul RGB cu culoarea galben daca fortele detectate sunt intre 5 si 15 Newtoni</li>
<li>3c. Aprinde led-ul RGB cu culoarea mov daca fortele detectate sunt intre 15 si 20 Newtoni</li>
<li>3d. In cazul in care forta detectata trece de 20 de Newtoni se apeleaza functia de ALARMA, aceasta porneste modulul de buzzer si aprinde succesiv ledul cu culorile rosu si albastru (asteptam un timp inainte sa reincepem sa verificam accelerometrul lasand astfel timp persoanei sa se ridice)</li>
</ul>

<h3>1.Verificare si initializare accelerometru</h3>
<p> Se verifica outputul accelerometrului si acesta se considera valoare de pornire a senzorului.</p>
<p> In cazul in care este specificate un offset acesta este aplicat valorilor de pornire. </p>

<h3>2.Citirea fortelor</h3>
<p> Se retine in variabila 'normAccel' valoarea normalizata a acceleratiei detectate de senzor </p>
<p> Prin insumarea patratelor acceleratiilor de pe fiecare axa se calculeaza forta generala aplicata asupra senzorului </p>

<h3>3.Alerta si verificare forta</h3>
<p> In functie de forta aplicata se seteaza culoarea ledului prin outputul a trei semnale analog pentru fiecare culoare de baza a ledului </p>

<h3>3*.Functia 'alarm'</h3>
<p> Functia porneste modulul buzzer pentru cateva secunde si alterneaza intre culoarea rosie si albastra </p>
<p> Dupa alertare se asteapta cateva secunde pentru ridicarea persoanei ce utilizeaza sistemul de alerta. </p>
