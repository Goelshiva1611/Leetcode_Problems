/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {
    let merapromise = new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(millis);
        }, millis);
    });
    return merapromise;
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */