# XDF Actions
Set of tools that are created for the [XDF](https://www.youtube.com/user/Xtremedefenceforce/channels) Arma 3 unit.

## XDF NiLOC
MP only presistent system. The reason for another such system is that we can have full controls of what/when to load during plays that better fit our game flows.

### Features
- External file based data store [INIDBI2] (https://forums.bohemia.net/forums/topic/186131-inidbi2-save-and-load-data-to-the-server-or-your-local-computer-without-databases) without bloat up server/client profiles
- Script based, no additional mod to install (it requires CBA and ACE3)
- Mission stats
  - time
  - all user placed map markers
- Players stats
  - locations
  - loadouts
  - health (every ACE medical records)
  - captive states
  - in/out vehicles
  - hunger / thirst
- AI stats (everything in Players except hunger/thirst)
  - formations
  - combat behaviours
- Vehicles stats
  - locations
  - damages (all hit parts)
  - crews
  - invertory (partial)
- Dead entities
  - AIs / vehicles will be killed on session load in where they were killed

# Notes
You can do whatever you like with the codes as stated in the license file. Of course, it would be appreicated if you credit me in your work. This is created to fit XDF playstyle so if you have any requirests (via bug reports) I might implement them if they also work for us.
