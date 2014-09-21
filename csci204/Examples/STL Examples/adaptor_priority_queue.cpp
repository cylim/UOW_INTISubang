// adaptor_priority_queue.cpp

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Message
{
   public:
   Message( string message = "Software problem",
      string source = "Message constructor", int security_level = 0 );
   // message - description of problem
   // source - site of problem
   // security_level - 0-10, 10 is most important

   bool operator<( const Message& rhs ) const;
   // compare security levels

   string message() const;
   int security_level() const;
   string source() const;

   private:
   string message_, source_;
   int security_level_;
};

inline
Message::Message( string message, string source, int security_level )
   : message_( message ), source_( source ),
     security_level_( security_level )
{} // empty

bool Message::operator<( const Message& rhs ) const
{  return security_level() < rhs.security_level(); }

string Message::message() const
{  return message_; }

string Message::source() const
{  return source_; }

int Message::security_level() const
{  return security_level_; }


int main( )
{
   const char* message[] = { "situation normal",
      "visitor needs a pass", "lights on in Building 7",
      "visitor still needs a pass",
      "smoke from corner of Building 7",
      "call from Lab 46, Building 7 - they smell smoke",
      "fire alarm, Building 7, Lab 46" };
   const char* source[] = { "South gate", "West gate", "South gate",
      "West gate", "South gate", "South gate", "South gate" };
   const int security_level[] = { 0, 1, 3, 2, 6, 7, 8 };
   const int num_messages
      = sizeof( security_level ) / sizeof( security_level[0] );

   priority_queue<Message> messages;

   cout << "MESSAGES IN CHRONOLOGICAL ORDER\n";
   for( int i = 0; i < num_messages; ++i )
   {
      cout << "Event " << (i+1) << ": Security level - "
         << security_level[i] << "\n\t" << source[i] << " reports "
         << message[i] << endl;

      messages.push( Message( message[i], source[i],
         security_level[i] ) );
   }

   cout << "\n\nMESSAGES IN PRIORITY ORDER\n";
   while( !messages.empty() )
   {
      cout << "Security level - "
         << messages.top().security_level() << "\n\t"
         << messages.top().source() << " reports "
         << messages.top().message() << endl;
      messages.pop();
   }
}

