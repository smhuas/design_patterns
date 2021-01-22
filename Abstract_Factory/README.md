Observations:-
say we have a third party library provider who gives us the Factory classes of different types of families of Operating system GUI's.
when ever new OS GUI is added to the library, using Abstract Factory design pattern, no need to change in client code.
the changes are only in library side, that too any new changes are just add-on's. No need to change existing library code.


in library code:-
AbstractFactory_Interface.hpp   --> provides the interface to create buttons and checkboxes.
Button_Interface.hpp            --> provides the interface to create buttons
Checkbox_Interface.hpp          --> provides the interface to create Checkboxes

The above are the standard files to add any number of factory families.
Currently we have two families(windows, mac).
In future add-on any number of families with out changing existing code.

in client code:-
just include the library in the cmake file.
create client class(Application) and using the Abstract factory interface, know what functions exists, using them to construct products.