prefix = /usr/local

all:
	g++ ./bin/createstructure.cpp -o createstructure -lcurl -lcrypto -std=c++17

install:
	g++ ./bin/createstructure.cpp -o createstructure -lcurl -lcrypto -std=c++17
	echo "DESTDIR: $(DESTDIR)"
	echo "prefix: $(prefix)"
	install createstructure $(DESTDIR)$(prefix)/bin
	install createstructure.1 $(DESTDIR)$(prefix)/share/man/man1
	install createstructure.2 $(DESTDIR)$(prefix)/share/man/man1

clean:
	rm -f createstructure
