# API Nginx Module

## Directive

### api_delay_client_max_body_check [on|off]

default: off

Delay client_max_body_size check until the body is read.

### api_mirror_on_demand [on|off]

default: off

Disable request mirror until we enable it in the Lua code.

## Block

### lua

Apply ngx.shared.DICT that shared by http and stream subsystem.

example:

```nginx
lua {
    lua_shared_dict prometheus-metrics 15m;
}
```
