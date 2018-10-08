<!DOCTYPE html>
<html>
<title>Homepage</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
<link rel="stylesheet" href="https://www.w3schools.com/lib/w3-theme-black.css">
<link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Roboto">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<style>
html,h1,h2,h3,h4,h5,h6 {font-family: "Roboto", sans-serif;}
.w3-sidebar {
  z-index: 3;
  width: 250px;
  top: 0px;
  bottom: 0;
  height: inherit;
}
body
{
font-family: "Roboto", sans-serif;
background:url("https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&ved=2ahUKEwj62Nb33fPdAhVJbysKHRoTAf0QjRx6BAgBEAU&url=http%3A%2F%2Fwww.forkedrivergazette.com%2Fstockton-announces-full-list-events-suicide-prevention-month-healing-hope%2F&psig=AOvVaw2yOKPPsR4crtQ1fXG4oWrB&ust=1538981202240179");
background-repeat:no-repeat;
background-size:100% 100%;
}
</style>
<body>

<!-- Navbar
<div class="w3-top">
  <div class="w3-bar w3-theme w3-top w3-left-align w3-large">
    <a class="w3-bar-item w3-button w3-right w3-hide-large w3-hover-white w3-large w3-theme-l1" href="javascript:void(0)" onclick="w3_open()"><i class="fa fa-bars"></i></a>
    <a href="#" class="w3-bar-item w3-button w3-theme-l1">Logo</a>
    <a href="#" class="w3-bar-item w3-button w3-hide-small w3-hover-white">About</a>
    <a href="#" class="w3-bar-item w3-button w3-hide-small w3-hover-white">Values</a>
    <a href="#" class="w3-bar-item w3-button w3-hide-small w3-hover-white">News</a>
    <a href="#" class="w3-bar-item w3-button w3-hide-small w3-hover-white">Contact</a>
    <a href="#" class="w3-bar-item w3-button w3-hide-small w3-hide-medium w3-hover-white">Clients</a>
    <a href="#" class="w3-bar-item w3-button w3-hide-small w3-hide-medium w3-hover-white">Partners</a>
  </div>
</div>
 -->

<!-- Sidebar -->
<nav class="w3-sidebar w3-bar-block w3-collapse w3-large w3-theme-l5 w3-animate-left" id="mySidebar">
  <a href="javascript:void(0)" onclick="w3_close()" class="w3-right w3-xlarge w3-padding-large w3-hover-black w3-hide-large" title="Close Menu">
    <i class="fa fa-remove"></i>
  </a>
  <h4 class="w3-bar-item"><b>Menu</b></h4>
  <a class="w3-bar-item w3-button w3-hover-green" href="{% url 'myapp:home' %}">Home</a>
  <a class="w3-bar-item w3-button w3-hover-red" href="{% url 'myapp:aboutUs' %}">About Us</a>
  <a class="w3-bar-item w3-button w3-hover-blue" href="{% url 'myapp:contact' %}">Contact Us</a>
  <a class="w3-bar-item w3-button w3-hover-yellow" href="{% url 'myapp:join' %}">Join</a>
  <a class="w3-bar-item w3-button w3-hover-gray" href="{% url 'myapp:riskf' %}">Know the risk factors</a>
  <a class="w3-bar-item w3-button w3-hover-orange" href="{% url 'myapp:pre' %}">Prevention</a>  
</nav>

<!-- Overlay effect when opening sidebar on small screens -->
<div class="w3-overlay w3-hide-large" onclick="w3_close()" style="cursor:pointer" title="close side menu" id="myOverlay"></div>

<!-- Main content: shift it to the right by 250 pixels when the sidebar is visible -->
<div class="w3-main" style="margin-left:250px">

  <div class="w3-row w3-padding-64">
    <div class="w3-twothird w3-container">
      <h1 class="w3-text-teal">PREVENTION</h1>
	<h2 class="w3-text-teal">How Can You Help Yourself?</h2>
          <h3 class="w3-text-teal">Find A Therapist/Support Group</h3>
      <p style = "font-size:100%">Speaking to someone, whether by going to a therapist or by attending a support group, can help you feel better and improve your mental health. These resources can help you find a psychologist, psychiatrist, or support group near you.
	 </p>
	<h3 class="w3-text-teal">Make A Safety Plan</h3>
		<p style = "font-size:100%">A safety plan is designed to guide you through a crisis. As you continue through the steps, you can get help and feel safer. 
			Keep your plan easily accessible in case you have thoughts of hurting yourself
		</p>		
<ul style = "font-size:100%">
<li>Recognize your personal warning signs: What thoughts, images, moods, situations, and behaviors indicate to you that a crisis may be developing? Write these down in your own words.</li>
<li>Use your own coping strategies: List things that you can do on your own to help you not act on urges to harm yourself.</li>
<li>Socialize with others who may offer support as well as distraction from the crisis: List people and social settings that may help take your mind off of difficult thoughts or feelings.</li>
<li>Contact family members or friends who may help to resolve a crisis: Make a list of people who are supportive and who you feel you can talk to when under stress.</li>
<li>Ensure your environment is safe: Have you thought of ways in which you might harm yourself ? Work with a counselor to develop a plan to limit your access to these means</li>
</ul>
<h3 class="w3-text-teal">Use Your Support Network</h3>
		<p style = "font-size:100%">Leaning on your support network can help you cope during difficult moments and is an important step in getting help and moving forward.
		</p>		
<ul style = "font-size:100%">
<li>Express Yourself : 
During difficult situations, it is natural to shut down , but keeping your emotions bottled up makes it harder for your support network to help you. Reach out to people you trust who have the ability to be sympathetic and non-judgmental</li>
<li>Keep an Open Mind :
Keep in mind that the advice and support of others come from a good place. We may not necessarily agree with advice we are given, but staying open-minded and receptive to outside perspectives and opinions can help strengthen your support network. </li>
<li>Show Appreciation :
The people in your support network will stick with you through thick and thin, but it is also important to remember that friendships and relationships are a two-way street. Express your appreciation for the love and support that these special people bring into your life</li>

</ul>
    </div>
   </div>

  

  
    
  <!-- Pagination
  <div class="w3-center w3-padding-32">
    <div class="w3-bar">
      <a class="w3-button w3-black" href="#">1</a>
      <a class="w3-button w3-hover-black" href="#">2</a>
      <a class="w3-button w3-hover-black" href="#">3</a>
      <a class="w3-button w3-hover-black" href="#">4</a>
      <a class="w3-button w3-hover-black" href="#">5</a>
      <a class="w3-button w3-hover-black" href="#">»</a>
    </div>
  </div>
 -->

 
<!-- END MAIN -->
</div>

<script>
// Get the Sidebar
var mySidebar = document.getElementById("mySidebar");

// Get the DIV with overlay effect
var overlayBg = document.getElementById("myOverlay");

// Toggle between showing and hiding the sidebar, and add overlay effect
function w3_open() {
    if (mySidebar.style.display === 'block') {
        mySidebar.style.display = 'none';
        overlayBg.style.display = "none";
    } else {
        mySidebar.style.display = 'block';
        overlayBg.style.display = "block";
    }
}

// Close the sidebar with the close button
function w3_close() {
    mySidebar.style.display = "none";
    overlayBg.style.display = "none";
}
</script>

</body>
</html>
