# Projecte: Escacs

#### Metodologia de la Programació

#### Curs 2021 - 2022


### Objectius de la sessió

#### 1. Presentació i organització del projecte

#### 2. Explicar les tasques a realitzar a la primera versió del projecte


### Organització del projecte

§ **Grupsde 2 persones:** hemobertaCaronteunainscripció agrupsperquèpugueuindicaramb
quifareuelprojecte.
§ Apunteu-vosaundelssubgrupscorresponentsalvostregrupdeclasse.

§ Elprojecteéspartdel **treballautònom** del’assignatura.Durantles horesdeclassededicarem
algunessessionsaseguimentiavaluaciódeltreball.


### Objectiu del projecte

Elvostreprogramafinalhauràdepermetre:

§ **Inicialitzarunapartida** desdezerooapartird’un **estatinicial** guardatenunfitxerdetext.

§ **Jugarlapartida** apartirdel’estatinicial.Acada **torn** d’unjugador:

```
§ Seleccionarunapeça permoure.
§ Determinartotsels movimentsvàlids quepotferlapeça.
§ Moure la peça aunanovaposiciódinsdelsmovimentsvàlids.
§ Actualitzar l’estatdel tauler tenintencomptesiesmataalgunapeçadelcontrari.
```
§ **Guardar** totsels **moviments** queesfandurantlapartidaenunfitxer.

§ **Reproduir** una **partida** prèviamentjugadaexecutantelsmovimentsguardatsenunfitxer.

Podreuafegir **funcionalitatsextres** ,sivoleu,quecomptaranpositivamentcoma **puntsaddicionals**
ala **notafinal** delprojecte.

Disseny i desenvolupament d’una versió completament funcional del joc del **escacs** , posant en
pràctica els conceptes que anem explicant a les sessions de classe.


## Planificació del projecte

El projecte el desenvoluparem en dues fases, que es correspondran amb el lliurament parcial i el
lliurament final del projecte.

**Primera versió del projecte:**

§ Inicialitzar el tauler del joc a partir de la informació guardada a un fitxer de text.
§ Determinar els moviments vàlids de qualsevol peça del tauler.
§ Moure una peça, comprovant que el moviment és vàlid.
§ Mostrar l’estat actual del tauler.
§ En aquesta primer versió treballarem sense visualització gràfica. Tindreu un test d’autoavaluació a Caronte
per poder validar el correcte funcionament de les diferents funcionalitats.

**Segona versió del projecte:**
§ Implementar la part gràfica del joc i la interacció del jugador amb el tauler durant el seu torn.
§ Implementar el desenvolupament complet d’una partida a partir d’un estat inicial, alternant els torns dels
jugadors fins al final de la partida.
§ Guardar en un fitxer els moviments que es fan durant el desenvolupament de la partida.
§ Reproduir una partida prèviament jugada executant els moviments guardats en un fitxer.


## Primera versió del projecte

#### Inicialitzar una partida

S’haurà de poder inicialitzar l’estat inicial de la partida a partir de la informació guardada en un fitxer.
El fitxer contindrà la informació de la posició inicial de cada peça seguint el format que es mostra en
aquest exemple:

0. Rb
0. Da
0. Ac
0. Cc
0. Pa
0. Pb
1. Re
1. Df
1. Tc
1. Ae
1. Pb
1. Pc

```
Codificació del jugador:
0: blanques
1: negres
```
```
Tipus de la peça:
R: Rei
D: Dama
T: Torre
A: Alfil
C: Cavall
P: Peó
```
```
Posició dins del tauler:
8 T
7 D P R
6 P A A D
5
4
3 C
2 P P
1 R
a b c d e f g h
```
```
Negres
```
```
Blanques
```

## Primera versió del projecte

#### Determinarelsmovimentsvàlidsd’unapeça

Donadaunaposiciódeltauler,s’hauràdepoderrecuperarelconjuntdeposicionsaonespotmourelapeça
queocupaaquellaposiciótenintencompte:
§ Nomésespodenferelsmovimentspermesosenfunciódeltipusdepeça.
§ Unapeçanoespotmoureaunaposicióocupadaperunaaltrapeçadelmateixjugador,peròsíquees
potmoureaunaposicióocupadaperunapeçadeljugadorcontrari.
§ Unapeçanopotavançarmésenllàd’unaposicióocupadaperunaaltrapeça,jasiguidelmateixjugadoro
deljugadorcontrari.
8 **T**
7 **D P R**
6 **P A A D**
5
4
3 **C**
2 **P P**
1 **R**
a b c d e f g h

```
8 T
7 D P R
6 P A A D
5
4
3 C
2 P P
1 R
a b c d e f g h
```
```
8 T
7 D P R
6 P A A D
5
4
3 C
2 P P
1 R
a b c d e f g h
```
```
Tipus de la peça:
R: Rei
D: Dama
T: Torre
A: Alfil
C: Cavall
P: Peó
```

## Primera versió del projecte

#### Recordem:movimentsdelespeces

§ **Rei** :potavançarunasolaposicióenqualsevoldeles 8 direccionspossibles.
§ **Dama** :potavançartantesposicionscomvulguienqualsevoldeles 8 direccionspossibles.
§ **Torre** : pot avançar tantes posicions com vulgui en qualsevol de les direccions horitzontal o
vertical.
§ **Alfil** :potavançartantesposicionscomvulguienqualsevoldelesdireccionsdiagonals.
§ **Cavall** : avança en forma de ‘L’, dues posicions en horitzontal o vertical i una posició
perpendicularalprimermoviment.
§ **Peó** : siestà a la sevaposició inicial al tauler, potavançar una o dues posicionsendavant. Si
està a qualsevol altra posició, només pot avançar una posició endavant. Per matar, pot
avançarunaposicióendiagonalcapaqualsevoldelsdoscostats.
§ **No considerarem** altrestipusde **moviments** o accions **especials** alaversió bàsicamínimadel
joc(hopodeuinclouresivoleucomafuncionalitatsextres):
§ Enrocentreelreiilatorre.
§ Canvidelpeóperunaaltrapeçasiarribaalfinaldeltauler.

```
Tipus de la peça:
R: Rei
D: Dama
T: Torre
A: Alfil
C: Cavall
P: Peó
```

## Primera versió del projecte

#### Estructura de classes


## Primera versió del projecte

#### Classe Piece

§ Guarda la informació d’una peça del tauler de joc
§ Té atributs per guardar el color (de quin jugador és) i el tipus de la peça.
§ Afegiu els mètodes que facin falta, bàsicament constructor, gettersi setters
i també algun mètode per convertir la peça en un string(serà necessari per
mostrar la informació del tauler per pantalla).
§ Per codificar el tipus i el color de les peces us donem ja declarats aquests
dos tipus enumerate:
typedef enum {
CPT_King,
CPT_Queen,
CPT_Rook,
CPT_Bishop,
CPT_Knight,
CPT_Pawn,
CPT_EMPTY
} ChessPieceType;

```
typedef enum {
CPC_Black,
CPC_White,
CPC_NONE
} ChessPieceColor;
```
```
Tipus de la peça:
R: Rei
D: Dama
T: Torre
A: Alfil
C: Cavall
P: Peó
```

## Primera versió del projecte

#### Classe ChessBoard

§ Guarda la informació del tauler del joc
§ Té un atribut per guardar una matriu on cada posició correspon
a una de les caselles del joc i conté la informació de la peça que
hi ha en aquella posició.
§ A les posicions on no hi ha cap peça es pot guardar una peça de
tipus CPT_EMPTY
§ Haureu d’implementar els mètodes públics de la classe
ChessBoard. Per implementar-los haureu d’implementar
altres mètodes privats auxiliars que us ajudin a estructurar el
codi seguint els principis de la descomposició modular.


## Primera versió del projecte

#### Classe ChessBoard: mètodes

void LoadBoardFromFile(const string& path)

§ Inicialitza el tauler de joc a partir de la informació d’un fitxer de text en el format que s’ha explicat
abans

0. Rb
0. Da
0. Ac
0. Cc
0. Pa
0. Pb
1. Re
1. Df
1. Tc
1. Ae
1. Pb
1. Pc

```
Codificació del jugador:
0: blanques
1: negres
```
```
Tipus de la peça:
R: Rei
D: Dama
T: Torre
A: Alfil
C: Cavall
P: Peó
```
```
Posició dins del tauler:
8 T
7 D P R
6 P A A D
5
4
3 C
2 P P
1 R
a b c d e f g h
```
```
Negres
```
```
Blanques
```

## Primera versió del projecte

#### Classe ChessBoard: mètodes

VecOfPositions GetValidMoves (const ChessPosition& pos) const

§ Calcula tots els moviments vàlids que pot fer la peça que ocupa la posició que es passa com a
paràmetre.
§ Els moviments vàlids es retornen com el conjunt de posicions a les es pot moure la peça.
§ Per guardar cadascuna de les posicions es pot fer servir la **classe ChessPosition.**

```
§ Guarda la fila i la columna d’una posició del tauler
§ Afegiu els mètodes que facin falta, bàsicament constructor, gettersi setters i també
algun mètode per convertir la posició en un stringo inicialitzar-la a partir d’un string.
§ Per poder executar el test que us donarem a Caronte:
§ Cal que tingui un constructor que rebi com a paràmetre un stringen el format
que hem indicat abans quan hem explicat la inicialització de la partida.
§ Cal que tingui definida la sobrecàrrega de l’operador ==per poder comparar si
dues posicions són iguals o no.
```
#### Classe ChessPosition


## Primera versió del projecte

#### Classe ChessBoard: mètodes

VecOfPositions GetValidMoves (const ChessPosition& pos) const

§ El mètode retorna totes les posicions vàlides en un vector (utilitzant la classe de la llibreria estàndard
vectorque expliquem més endavant).
§ Al codi inicial que us donarem trobareu aquesta declaració del tipus VecOfPositionsper guardar
aquest vector de posicions:
typedef vector<ChessPosition> VecOfPositions;


## Primera versió del projecte

#### Classe ChessBoard: mètodes

VecOfPositions GetValidMoves (const ChessPosition& pos) const

```
8 T
7 D P R
6 P A A D
5
4
3 C
2 P P
1 R
a b c d e f g h
```
**Exemple**

```
GetValidMoves(ChessPosition(‘c3’))
```
```
[ChessPosition(‘a4’),
ChessPosition(‘b5’),
ChessPosition(‘d5’),
ChessPosition(‘e4’),
ChessPosition(‘e2’),
ChessPosition(‘d1’)]
```

## Primera versió del projecte

#### Classe ChessBoard: mètodes

bool MovePiece (const ChessPosition& posFrom, const ChessPosition& posTo)

```
§ Mou la peça que ocupa la posició del paràmetre posFroma la posició del paràmetre posTo.
§ Ha de comprovar que la posició destí estigui dins dels moviments vàlids de la peça.
§ Si no ho està no fa el moviment i retorna false.
```

## Primera versió del projecte

#### Classe ChessBoard: mètodes

string ToString() const

```
§ Genera un stringamb l’estat actual del tauler de joc en el format que especifiquem a continuació
```
```
8 __ __ wR__ __ __ __ wR
7 bQ__ wP__ wKwPwPwP
6 __ wPbB__ wBwQ__ __
5 __ __ __ __ __ __ __ __
4 __ __ __ __ __ __ __ __
3 __ __ bH__ wP__ __ __
2 bPbPbP__ __ __ bPbP
1 __ bK__ bR__ __ __ __
a b c d e f g h
```
```
Tipus de la peça:
R: Rei
D: Dama
T: Torre
A: Alfil
C: Cavall
P: Peó
```
```
Codificació del jugador:
0: blanques (w)
1: negres (b)
```

## Organització del projecte

§ Laproperasessiódeseguimentdelprojecteseràel **divendres 8 d’abril**.

```
§ Revisió del queheu avançat en elprojecte i de com plantegeu el dissenyde les classes
PieceiChessPositionilaimplementaciódelsmètodesdelaclasseChessBoard.
§ Comptaràun 20 %delanotadellliuramentparcial.
```
§ Ellliuramentparcialdelprojecteamblaimplementaciódelaprimeraversió seràeldivendres
**29 d’abril**. Alasetmana següentfaremunaavaluació online individualdellliuramentdecada
grup.

§ ACarontetindreuun **testd’autoavaluació** delsmètodespúblicsdelaclasseChessBoardque
heud’implementar.


## Propers passos: alguns consells

1. Penseuquinsmètodes uspodenfer faltaala classePiece.Feuuna primeraimplementació
    delaclasse.
2. Penseu quins mètodes us poden fer falta a la classe ChessPosition. Feu una primera
    implementaciódelaclasse.
3. Feu la implementació del mètode LoadBoardFromFile de la classe ChessBoard per
    poderinicialitzareltaulerdefitxer.Siusfafaltaafegiromodificaralgunmètodealesclasses
    PieceiChessPosition,adapteulaimplementaciód’aquestesclasses.
4. Penseu com podeu descomposar el codi del mètode GetValidMoves amb funcions més
    petitesisimples.
    § Compodem organitzarelcodi delmètode perpoderimplementar fàcilment elcodiper
       recuperarelsmovimentsvàlidspercadatipusdepeça?
    § Hihapartsdelcodiquesiguincomunsadiferentstipusdepeces?Compodemorganitzar
       elcodiperevitarduplicaraquestespartscomunesdelcodi?
5. ComenceuaimplementarelcodidelmètodeGetValidMoves,percadatipusdepeça.


#### Classe vector

§ Permet gestionar arraysde longitud indefinida de qualsevol tipus
§ El tipus de l’arrays’especifica en el moment de la declaració de l’arrayutilitzant _templates_.

§ La mida de l’arrays’ajusta automàticament al número d’elements que hi tenim guardats:
§ Si el número d’elements creix molt, automàticament es reserva més memòria i es fa una còpia
de tots els elements al nou espai de memòria.

```
#include <vector>
using namespace std;
```
```
vector<int> v;
```
```
vector<Complex> v;
```
```
v: ... ...
```
```
v: ... ...
```
```
tipusint
```
```
Tipus dels elements del vector tipusComplex
```
```
El tamanys’ajusta
automàticament
```
```
https://en.cppreference.com/w/cpp/container/vector
```
### Classe vector


#### Classe vector: accés als elements

```
§ L’accés es pot fer per índex (començant per 0) igual que als arrays.
§ Només es pot accedir als índexs que corresponen a posicions vàlides (entre 0 i el nº d’elements actuals del
vector).
§ Inicialment, el nº d’elements del vector és 0. Si intentem accedir a qualsevol element tindrem un error
d’accés
§ Podem recuperar el nº d’elements actual cridant al mètode size()
§ El nº d’elements actuals del vector canvia quan:
§ Afegim un element al vector (operacions push_back, insert)
§ Eliminem un element al vector (operacions pop_back, erase)
§ Redimensionem explícitament el tamanydel vector (operació resize)
vector <int> v;
v[ 0 ] = 1;
```
```
v:
```
```
vector <int> v;
v.push_back(0);
v[ 0 ] = 10;
```
```
v: 10
```
```
vector <int> v;
v.resize(5);
for (int i = 0; i < v.size(); i++)
v[i] = i;
```
```
v:^01234
v.size() v.size() 5
1
v.size()^0
```
### Classe vector


### Classe vector

#### Classe vector: afegir/eliminar al final del vector

§ **push_back(element)** : afegeix un element al final del vector, incrementant el nº d’elements
actual.

§ **pop_back()** : elimina l’últim element del vector, decrementantel nº d’elements actual

```
vector <int> v;
v.resize(5);
for (int i = 0; i < v.size(); i++)
v[i] = i;
```
```
v.push_back(5);
```
```
v.pop_back();
```
```
v:^01234
v.size()^5
```
```
v:^012345
v.size()^6
```
```
v:^01234
v.size()^5
```

### Classe vector

#### Exemple

```
class Estudiant
{
private:
string m_nom;
string m_NIU;
vector<string> m_assignatures;
};
```
```
void Estudiant::afegeixAssignatura(const string& assignatura)
{
m_assignatures.push_back(assignatura);
}
```
```
void Estudiant::mostraAssignatures()
{
for (int i = 0; i < m_assignatures.size(); i++)
cout << m_assignatures[i] << endl;
}
```

