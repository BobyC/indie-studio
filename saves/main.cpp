#include "SaveHandler.hh"

using json = nlohmann::json;

int main()
{
  SaveHandler* toto = new SaveHandler;

  Save me("tommy", SaveHandler::getCurrentTime(), "010101010010", 64);
  Save you("Ottyo", SaveHandler::getCurrentTime(), "010101010010658465465465", 545464);
  toto->save(me);
  toto->save(you);
  delete toto;
  return 0;
}
