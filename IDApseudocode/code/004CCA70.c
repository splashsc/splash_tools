void *calloc(size_t nmemb, size_t size)
{
  MEMORY[0](nmemb, size);
  return (void *)ping_wan_gw_get_state();
}
// 4CCA80: using guessed type int ping_wan_gw_get_state(void);

