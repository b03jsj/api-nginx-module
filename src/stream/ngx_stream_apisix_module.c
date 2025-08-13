#include <ngx_stream.h>
#include <ngx_stream_lua_api.h>
#include "ngx_stream_api_module.h"


typedef struct {
    unsigned             proxy_ssl_enabled:1;
} ngx_stream_api_ctx_t;


static ngx_stream_module_t ngx_stream_api_module_ctx = {
    NULL,                                    /* preconfiguration */
    NULL,                                    /* postconfiguration */

    NULL,                                    /* create main configuration */
    NULL,                                    /* init main configuration */

    NULL,                                    /* create server configuration */
    NULL,                                    /* merge server configuration */
};


ngx_module_t ngx_stream_api_module = {
    NGX_MODULE_V1,
    &ngx_stream_api_module_ctx,       /* module context */
    NULL,                                /* module directives */
    NGX_STREAM_MODULE,                   /* module type */
    NULL,                                /* init master */
    NULL,                                /* init module */
    NULL,                                /* init process */
    NULL,                                /* init thread */
    NULL,                                /* exit thread */
    NULL,                                /* exit process */
    NULL,                                /* exit master */
    NGX_MODULE_V1_PADDING
};


ngx_int_t
ngx_stream_api_upstream_enable_tls(ngx_stream_lua_request_t *r)
{
    ngx_stream_api_ctx_t       *ctx;

    ctx = ngx_stream_lua_get_module_ctx(r, ngx_stream_api_module);
    if (ctx == NULL) {
        ctx = ngx_pcalloc(r->pool, sizeof(ngx_stream_api_ctx_t));
        if (ctx == NULL) {
            return NGX_ERROR;
        }

        ngx_stream_lua_set_ctx(r, ctx, ngx_stream_api_module);
    }

    ctx->proxy_ssl_enabled = 1;

    return NGX_OK;
}


ngx_int_t
ngx_stream_api_is_proxy_ssl_enabled(ngx_stream_session_t *s)
{
    ngx_stream_api_ctx_t       *ctx;

    ctx = ngx_stream_get_module_ctx(s, ngx_stream_api_module);

    return ctx != NULL && ctx->proxy_ssl_enabled;
}
