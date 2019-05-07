<h1>AUDIO MANAGER & SPATIAL AUDIO RESEARCH</h1>

Hi, i'm Oscar Larios, student of the [Bachelor’s Degree in Video Games by UPC at CITM](https://www.citm.upc.edu/ing/estudis/graus-videojocs/ "Link to the Degree"). This content is generated for the second year’s subject Project 2, under supervision of lecturer Ricard Pillosu.


<h2>A little bit of history<h2>

  Sound has become a very important theme in the world of the videogames nowadays, it's inexplicable for us to play to a game and to not   have some type of music or fx's. But this hasn't always been the case.
  If we look a few years ago, more exactly in the 70's, when Pong was released as an arcade videogame, it already had some fx's to show   when the players collided with the ball or when the ball collided with the walls, but it was just a change of the pitch in the "beep"   sound. This small fx already creates the sensation of different actions(padding the ball, collisding with the wall or scoring)
  
  Later in the 80's with the NES in the market, the sound in videogames improved, but the size memeory that 1 NES game had as an         
  average(384kb) didn't left music composers too much space for work, so most of the sound in that time were simple(4 tracks per game)   
  and it was simple and basic computer sounding waveforms.
  Nowadays it's totally different, we can create a videogame with lots of cool fx's and music without catching our fingers with some 
  memory issues

<h2>Audio Manager & Spatial Audio, what are they?<h2>
<h3>Audio Manager</h3>
  An Audio Manager is a tool/part of the code of our videogame, that let's us create, manipulate or erase Music and Fx's in a game.
  In our case, we will be using j1Audio.h and j1Audio.cpp files to do so.
<h3>Spatial Sound</h3>
  Spatial Sound is a sound effect that allows us the player/listener to recognize the space, direction of the sound and distance           between us and that sound while listening to it. Some people call it the 3d sound effect
  Nowadays is a really common sound effect in the videogames, as we can see in fps games this is key for example, to figure out the       position of the enemy player.
  A good example is Apex Legends, in this fps we can hear from where position the enemy is shooting us, or from which way he is walking.
  This feature allows the players to train that sound accuracy to figure out faster and more effectively from which direction he will     face an unseen enemy.
  
 
<h2>How to manage it?</h2>
    In this research we will see how we can manage this spatial sound effect for our games, using the well known SDL_Mixer library
    Check the [doc](https://www.google.com)
    
  <h3>SDL_Mixer</h3>
  <h3>Core concepts & functions</h3>
  
<h2>Exercise</h2>
Now that we have reviewed the functions and concepts we will use, we can start with the exercise. The exercise will consist into inplementate a function(Spatial) that will relate 2 entities(emitter and receiver) and a fx. This fx will be assignated to the emitter, and the receiver(Player) will hear it different from a different direction or distance.
  <h3>TODO 1</h3>
  In the first TODO we will allocate as much channels as we desire. Keep in mind this channels will be used for the exercise, so create   at least 10(also don't create 1000!)
   <h3>TODO 2</h3>
    <h3>TODO 3</h3>
     <h3>TODO 4</h3>
      <h3>TODO 5</h3>
      
      
 <h2>TODO Solutions</h2>
 
 <h2>Sources</h2>
