function demo7tonality
%To get familiar with some approaches of tonal analysis using MIRtoolbox, 
% and to assess their performances.  

% Part 1. We will first investigate the performance of the chromagram
% analysis, using very simple musical samples. 

% 1.3. In the audio file �trumpet�, the same pitch is played by a trumpet.
% Compute its chromagram. What are the chromas detected by the function? 
% Can you explain the result?
mirchromagram('trumpet')

% 1.4. A more detailed representation of the chromagram can be obtained by 
% decomposing each pitch class into its different possible absolute values. 
% For that purpose, just add the parameter: 
c = mirchromagram('trumpet','Wrap',0) 

% 1.5. Compute also the key strength related to the chromagram. 
mirkeystrength(c) 

pause, close all

% 1.6. In the audio file �pianoF4�, the same pitch is  played by a piano.
[ks c] = mirkeystrength('pianoF4') 

a = miraudio('pianoF4','excerpt',.7,2);
[ks c] = mirkeystrength(a)

pause, close all

% 1.7. Investigate the chromagram analysis of triad chords
[ks c] = mirkeystrength('Amin3')
p = mirpeaks(ks)
mirkey(p)

pause, close all

[k kc ks] = mirkey('Amaj3')
[k kc ks] = mirkey('Amin4')
[k kc ks] = mirkey('Amaj4')

pause, close all

[k kc ks] = mirkey('Amin5')
[k kc ks] = mirkey('Amaj5')
[k kc ks] = mirkey('Cmaj')

pause, close all

[k kc ks] = mirkey(miraudio('Amin3','Excerpt',.2,1))
[k kc ks] = mirkey(miraudio('Amin4','Excerpt',.2,1))
[k kc ks] = mirkey(miraudio('Amaj3','Excerpt',.2,1))
[k kc ks] = mirkey(miraudio('Amaj4','Excerpt',.2,1))

pause, close all

[k kc ks] = mirkey(miraudio('Amin5','Excerpt',.2,1))
[k kc ks] = mirkey(miraudio('Amaj5','Excerpt',.2,1))
[k kc ks] = mirkey(miraudio('Cmaj','Excerpt',.2,1))

pause, close all
 
%Part 2. Let's analyze several extracts from 
%real music. For each extract, try the 
%following: 

%2.1. Listen to the piece: 
mirplay('vivaldi') 
soundsc(sin(2*pi*440*(0:1/8192:1)))

%2.2. Compute the chromagram of the 
%whole extract. What tonal center could be 
%inferred from the curve? Does it 
%correspond to your expectation? 
c = mirchromagram('vivaldi')

%2.3. Compute the key strength related to 
%the chromagram. Is the result congruent 
%with the tonality inferred in 2.1. and 2.2.? 
ks = mirkeystrength(c)
[k kc ks] = mirkey(ks)

%2.4. A more detailed representation of the 
%key strengths can be obtained by 
%computing the self-organizing map: 
som = mirkeysom(c)

pause, close all

%2.5. Analyse in the same way other audio files
[k kc ks] = mirkey('czardas')
mirkeysom('czardas')

pause, close all

%Part 3. The temporal evolution of the 
%tonal dimension can be assessed by 
%decomposing first the audio into frames
[k kc ks] = mirkey('czardas','frame')
mirkeysom('czardas','frame')