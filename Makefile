prefix = /usr/local

all:
	g++ ./bin/createstructure.cpp -o createstructure -lcurl -lcrypto -std=c++17

install:
	g++ ./bin/createstructure.cpp -o createstructure -lcurl -lcrypto -std=c++17
	echo "DESTDIR: $(DESTDIR)"
	echo "prefix: $(prefix)"
	install createstructure $(DESTDIR)$(prefix)/bin
	install -m 644 createstructure.1 $(DESTDIR)$(prefix)/share/man/man1/createstructure.1
	install -m 644 createstructure.2 $(DESTDIR)$(prefix)/share/man/man1/createstructure.2

clean:
	rm -f createstructure
