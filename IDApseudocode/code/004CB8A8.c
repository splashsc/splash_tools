char *iptv_get_new_token()
{
  const char *v0; // $v0
  _DWORD *v1; // $v0
  char *result; // $v0

  iptv_token_init_and_check_timeout();
  v0 = (const char *)common_get_token();
  v1 = iptv_token_create(v0);
  if ( v1 )
    result = (char *)(v1 + 1);
  else
    result = "";
  return result;
}
// 6A8320: using guessed type int common_get_token(void);

