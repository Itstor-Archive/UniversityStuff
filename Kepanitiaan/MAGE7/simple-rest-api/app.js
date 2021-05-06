const express = require("express");
const mongoose = require('mongoose')

const app = express();
const port = 5000;
const dataRouter = require("./routes/routes");

mongoose.connect('mongodb://localhost:27017/restapitest', { 
    useNewUrlParser: true,
    useUnifiedTopology: true,
    useFindAndModify: false,
})

const db = mongoose.connection;
db.on('error', err => console.error(err));
db.once('open', () => console.log('Connected'));

app.use(express.json());

app.use('/api', dataRouter);

app.listen(port, () => {
    console.log(`App listening at http://localhost:${port}`);
});