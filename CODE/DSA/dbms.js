document.getElementById("loginForm").addEventListener("submit", function(event) {
    event.preventDefault();

    // Retrieve form data
    var username = document.getElementById("username").value;
    var password = document.getElementById("password").value;

    // Simple validation (this can be expanded with more complex checks)
    if (username === "admin" && password === "password") {
        document.getElementById("message").style.color = "green";
        document.getElementById("message").innerText = "Login successful!";
    } else {
        document.getElementById("message").innerText = "Invalid username or password.";
    }
});
