OPENRESTY_PREFIX ?= /usr/local/openresty
INSTALL ?= install

.PHONY: install

install:
	$(INSTALL) -d $(OPENRESTY_PREFIX)/lualib/resty/api/
	$(INSTALL) -m 664 lib/resty/api/*.lua $(OPENRESTY_PREFIX)/lualib/resty/api/
	$(INSTALL) -d $(OPENRESTY_PREFIX)/lualib/resty/api/stream
	$(INSTALL) -m 664 lib/resty/api/stream/*.lua $(OPENRESTY_PREFIX)/lualib/resty/api/stream
	$(INSTALL) -d $(OPENRESTY_PREFIX)/lualib/resty/api/stream/xrpc
	$(INSTALL) -m 664 lib/resty/api/stream/xrpc/*.lua $(OPENRESTY_PREFIX)/lualib/resty/api/stream/xrpc
