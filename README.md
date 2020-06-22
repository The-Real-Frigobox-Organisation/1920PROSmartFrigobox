# Smart Frigobox

Wij hebben als project een smart frigobox ontwikkeld.

Het initiële idee was om als basisproduct een zelfrijdend karretje te ontwikkelen met een koelbox erop. Dit karretje kan zelfstandig een applicatie volgen die zijn positie doorstuurt. De koelbox kunnen we uitbreiden met enkele smart-functies zoals een volgfunctie, temperatuurmetingen, smart-lock en een inventaris.

Corona stak echter een klein stokje tussen de spaken.

Het uiteindelijk prototype is in staat om zowel data te ontvangen als te versturen naar de mobiele applicatie. De verschillende delen zijn allemaal ontwikkeld, ze zijn enkel niet samengesmolten tot één geheel.

## De applicatie

De applicatie is ontwikkeld in het mobiele Framework Flutter. De applicatie heeft als doel de locatie door te geven aan de frigobox en de data van de koelbox uit te lezen.

## De elektronica

Het brein van het rijdend karretje is een Arduino Mega. De arduino is verbonden met de mobiele applicatie via Bluetooth. Aan de Arduino worden alle smart-functies geschakeld via de IO.

De features zijn: 
- Smart-lock
- temperatuurmeting
- inventaris
- volgfunctie

## De koelbox

De koelbox zou zelf gemaakt worden met MDF en isomo, maar dit is niet tot stand gebracht. Er zijn wel technische tekeningen gemaakt van het ontwerp en elektronica.

## Conclusie

Veel van de nodige code & technologieën zijn theoretisch uitgewerkt. Maar niet alle delen zijn tot één geheel gebracht door de "lockdown", om die reden is er weinig testing & debugging uitgevoerd. De basis van het project staat wel op poten.
