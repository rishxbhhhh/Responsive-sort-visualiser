const express = require('express');
const app = express();
const path = require('path');
app.use(express.static(path.join(__dirname, "public")))

app.use("/", (req, res, next) => {
    res.status(200).sendFile(path.join(__dirname, "index.html"));
})

app.listen(process.env.PORT || 3000, () => {
    console.log("running");
})