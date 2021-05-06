const express = require('express');
const dataRouter = express.Router();
const Data = require('../models/scheme')

dataRouter.get('/', async (req, res) => {
    const data = await Data.find();
    res.json(data)
    // res.send("Hello word")
});

dataRouter.get('/:nrp', async (req, res) => {
    try {
        const data = await Data.find({ nrp: req.params.nrp });
        res.send(data);
    } catch {
        res.status(404);
        res.send({error: "NRP tidak ditemukan"});
    }
});

dataRouter.post("/", async (req, res) => {
    const post = new Data({
        nama: req.body.nama,
        nrp: req.body.nrp,
        ipk: req.body.ipk
    });
    await post.save();
    res.send(post);
});

dataRouter.patch("/:nrp", async (req, res) => {
    try {
        const post = await Data.findOne({ nrp: req.params.nrp });

        if (req.body.ipk) {
            post.ipk = req.body.ipk;
        }

        await post.save();
        res.send(post);
    } catch {
        res.status(404);
        res.send({ error: "NRP tidak ditemukan" });
    }
});

dataRouter.delete("/:nrp", async (req, res) => {
    try {
        await Data.deleteOne({ nrp: req.params.nrp });
        res.status(204).send("Success");
    } catch {
        res.status(404);
        res.send({ error: "NRP tidak ditemukan" });
    }
});

module.exports = dataRouter;