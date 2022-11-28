int start_diagnosis()
{
  nvram_set("vue_health_score", "0");
  stop_dhcp_server_just_check();
  start_dhcp_server_just_check();
  stop_wan_gw_ping_check();
  start_wan_gw_ping_check();
  stop_wan_http_check();
  start_wan_http_check();
  stop_wan_dns_check();
  return start_wan_dns_check();
}
// 6A824C: using guessed type int stop_dhcp_server_just_check(void);
// 6A82E0: using guessed type int start_dhcp_server_just_check(void);
// 6A83EC: using guessed type int stop_wan_dns_check(void);
// 6A847C: using guessed type int stop_wan_http_check(void);
// 6A8610: using guessed type int stop_wan_gw_ping_check(void);
// 6A8698: using guessed type int start_wan_http_check(void);
// 6A87E4: using guessed type int start_wan_dns_check(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A897C: using guessed type int start_wan_gw_ping_check(void);

