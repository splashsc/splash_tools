struct tm *localtime(const time_t *timer)
{
  MEMORY[0](timer);
  return (struct tm *)get_json_data();
}
// 4CD0F0: using guessed type int get_json_data(void);

