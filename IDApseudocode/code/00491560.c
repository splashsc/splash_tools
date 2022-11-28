int __fastcall dns_more_dnswan_is_used(const char *a1)
{
  const char *v2; // $v0
  bool v3; // dc
  int result; // $v0

  v2 = (const char *)nvram_get("dns_more_def_out");
  if ( !v2 || !a1 || (v3 = strcmp(v2, a1) == 0, result = 117, !v3) )
    result = dns_more_rule_check_used_group((int)a1, 0);
  return result;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);

