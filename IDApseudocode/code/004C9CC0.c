int https_ssl_init()
{
  int v0; // $v0
  int v1; // $v0
  const char *v2; // $v0
  int v3; // $s1
  int v5; // $a3
  int v6; // $a3
  FILE *stream; // [sp+18h] [-Ch]
  FILE *streamb; // [sp+18h] [-Ch]
  FILE *streamc; // [sp+18h] [-Ch]
  FILE *streama; // [sp+18h] [-Ch]
  FILE *streamd; // [sp+18h] [-Ch]

  if ( https_init )
  {
    SSL_library_init();
    https_init = 0;
  }
  SSL_load_error_strings();
  v0 = TLSv1_2_server_method();
  v1 = SSL_CTX_new(v0);
  https_ssl_ctx = v1;
  if ( !v1 )
  {
    v3 = -1;
    streamd = stderr;
    ERR_print_errors_fp(stderr);
    fprintf(streamd, "%s[%d]: SSL_CTX_new failed!\n", "https_ssl_init", 56);
    return v3;
  }
  SSL_CTX_ctrl(v1, 77, 50331648, 0);
  if ( SSL_CTX_set_cipher_list(https_ssl_ctx, "HIGH:!aNULL:!MD5") )
  {
    SSL_CTX_set_verify(https_ssl_ctx, 0, 0);
    v2 = (const char *)nvram_get("mqtt_ai_ssl_file_sw");
    if ( v2 && !strcmp(v2, "1") && f_exists("/tmp/mqtt_ai_ssl_file/https_ca.crt") )
    {
      SSL_CTX_load_verify_locations(https_ssl_ctx, "/tmp/mqtt_ai_ssl_file/https_ca.crt", 0);
      SSL_CTX_set_default_passwd_cb_userdata(https_ssl_ctx, "123456");
      if ( SSL_CTX_use_certificate_file(https_ssl_ctx, "/tmp/mqtt_ai_ssl_file/https_server.crt", 1) )
      {
        if ( !SSL_CTX_use_PrivateKey_file(https_ssl_ctx, "/tmp/mqtt_ai_ssl_file/https_server.key", 1) )
        {
          stream = stderr;
          ERR_print_errors_fp(stderr);
          v5 = 90;
LABEL_18:
          fprintf(stream, "%s[%d]: https SSL_CTX_use_PrivateKey_file failed!\n", "https_ssl_init", v5);
          return -1;
        }
        goto LABEL_9;
      }
      streama = stderr;
      ERR_print_errors_fp(stderr);
      v6 = 83;
    }
    else
    {
      SSL_CTX_load_verify_locations(https_ssl_ctx, "/etc/https_ca.crt", 0);
      SSL_CTX_set_default_passwd_cb_userdata(https_ssl_ctx, "123456");
      if ( SSL_CTX_use_certificate_file(https_ssl_ctx, "/etc/https_server.crt", 1) )
      {
        if ( !SSL_CTX_use_PrivateKey_file(https_ssl_ctx, "/etc/https_server.key", 1) )
        {
          stream = stderr;
          ERR_print_errors_fp(stderr);
          v5 = 110;
          goto LABEL_18;
        }
LABEL_9:
        if ( SSL_CTX_check_private_key(https_ssl_ctx) )
        {
          v3 = 0;
          fprintf(stderr, "%s[%d]: ssl ctx init success !\n", "https_ssl_init", 121);
        }
        else
        {
          v3 = -1;
          streamc = stderr;
          ERR_print_errors_fp(stderr);
          fprintf(streamc, "%s[%d]: set https crt file failed!\n", "https_ssl_init", 118);
        }
        return v3;
      }
      streama = stderr;
      ERR_print_errors_fp(stderr);
      v6 = 103;
    }
    fprintf(streama, "%s[%d]: https SSL_CTX_use_certificate_file failed!\n", "https_ssl_init", v6);
    return -1;
  }
  streamb = stderr;
  ERR_print_errors_fp(stderr);
  fprintf(streamb, "%s[%d]: SSL_CTX_set_cipher_list!\n", "https_ssl_init", 67);
  return 0;
}
// 67BD40: using guessed type int https_init;
// 681504: using guessed type int https_ssl_ctx;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8200: using guessed type int __fastcall ERR_print_errors_fp(_DWORD);
// 6A827C: using guessed type int __fastcall SSL_CTX_check_private_key(_DWORD);
// 6A831C: using guessed type int SSL_load_error_strings(void);
// 6A8408: using guessed type int __fastcall SSL_CTX_set_cipher_list(_DWORD, _DWORD);
// 6A8418: using guessed type int __fastcall SSL_CTX_use_PrivateKey_file(_DWORD, _DWORD, _DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);
// 6A849C: using guessed type int TLSv1_2_server_method(void);
// 6A84B4: using guessed type int __fastcall SSL_CTX_load_verify_locations(_DWORD, _DWORD, _DWORD);
// 6A8544: using guessed type int __fastcall SSL_CTX_new(_DWORD);
// 6A8620: using guessed type int __fastcall SSL_CTX_use_certificate_file(_DWORD, _DWORD, _DWORD);
// 6A8664: using guessed type int __fastcall SSL_CTX_ctrl(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A86C0: using guessed type int SSL_library_init(void);
// 6A87AC: using guessed type int __fastcall SSL_CTX_set_default_passwd_cb_userdata(_DWORD, _DWORD);
// 6A882C: using guessed type int __fastcall SSL_CTX_set_verify(_DWORD, _DWORD, _DWORD);

