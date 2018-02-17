unsigned long signal_len,t1,t2;   //variable temp pour lequel le bouton est appuyé
int inputPin = 2;                 //pin pour le BOUTTON
int ledPin = 4;                   //pin pour la LED
String code = "";                 

void setup()

{
  Serial.begin(9600);
  pinMode(inputPin, INPUT_PULLUP); //"pullup resistor" pour simplifier le circuit
  pinMode(ledPin,OUTPUT);
}

void loop()
{
NextDotDash:
  while (digitalRead(inputPin) == HIGH) {}
  t1 = millis();                            //temps quand le boutton est pressé
  digitalWrite(ledPin, HIGH);               //LED "HIGH" quand le bouton est pressé (on)
  while (digitalRead(inputPin) == LOW) {}
  t2 = millis();                            //temps quand le boutton est relaché
  digitalWrite(ledPin, LOW);                //LED "low" quand le boutton est relaché (off)
  signal_len = t2 - t1;                     //temp pour lequel le bouton est appuyé
  if (signal_len > 50)                    
  {
    code += readio();                       //fonction pour lire "dot" ou "dash" (. ou _)
  }
  while ((millis() - t2) < 500)           //si le temps entre deux activation du boutton est plus grand que 0.5sec, passe la boucle et va a l'alphabet
  {     
    if (digitalRead(inputPin) == LOW)
    {
      goto NextDotDash;
    }
  }
  convertor();                          //fonction pour traduire le morse vers l'alphabet
}

char readio()
{
  if (signal_len < 600 && signal_len > 50)
  {
    return '.';                        //si le boutton est pressé moins de 0.6sec alors c'est un point (.)
  }
  else if (signal_len > 600)
  {
    return '-';                        //si le boutton est pressé plus de 0.6sec alors c'est un tiret (_)
  }
}

void convertor()
{
  static String letters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
                             ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "E"
                            };
  int i = 0;
  if (code == ".-.-.-")
  {
    Serial.print(".");        //pour casser la boucle
  }
  else
  {
    while (letters[i] != "E")  //boucle pour comparer le code avec les lettres
    {
      if (letters[i] == code)
      {
        Serial.print(char('A' + i));
        break;
      }
      i++;
    }
    if (letters[i] == "E")
    {
      Serial.println("");  //si ca ne correspond a aucune lettre, retourne une erreur
    }
  }
  code = "";                            //remise à zero du code
}
